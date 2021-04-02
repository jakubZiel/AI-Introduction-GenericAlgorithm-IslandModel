//
// Created by jakub on 21.03.2021.
//
#include <random>
#include "evolutionary_operations.h"
#include "../structures/structures.h"
#include <chrono>
#include <cmath>
#include <algorithm>

typedef std::pair<double, double> range;

//basic mutation, as a driving force behind exploration
//it happens for every new genome chosen for in process of choosing_for_reproduction
void mutation(Genome& gen, double mut_strength){

    std::vector<double> &genome = gen.genome;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 generator(seed);

    for (double & i : genome){

        std::normal_distribution<double> distribution(i, mut_strength);

        i = distribution(generator);
    }
}
//averaging crossing in basic form
Genome crossover(const Genome& par1, const Genome& par2){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 generator(seed);
    std::normal_distribution<double> distribution(0,1);
    Genome child;

    double weight = std::abs(distribution(generator));

    double crossed_gene;

    for (int i = 0; i < par1.genome.size(); i++){

        crossed_gene = weight * par1.genome[i] + (1 - weight) * par2.genome[i];
        child.genome.push_back(crossed_gene);
    }

    return child;
}
//choosing_for_reproduction based on rank in population, should be called when population is already sorted.
//  0 ====>  |        1st best        |      2nd      |    3rd    |  4th  |  5th  | 6th |  <====  1
// Probability of being chosen for tournament which the winner gets to reproduce

double reproduction_possibility(int rank, int population_size){
    auto mi = (double)population_size;

    return (-2 * rank + 1. + 2. * mi ) / std::pow(mi, 2);
}

//building array of probabilities for sorted population

std::vector<range> array_of_probabilities(const std::vector<Genome> &genomes) {
    std::vector<range> probabilities;
    double current = 0.0;
    range curr_range;

    for (int i = 0; i < genomes.size(); i++) {
        curr_range.first = current;
        curr_range.second = current = current + reproduction_possibility(i + 1, genomes.size());

        probabilities.push_back(curr_range);
    }

    //normalize to range 0 - 1

    for (range &r : probabilities) {
        r.first /= probabilities[probabilities.size() - 1].second;
        r.second /= probabilities[probabilities.size() - 1].second;
    }
    return probabilities;
}

//choose base choosing_for_reproduction set by playing tournaments, winner of tournament
// is begin added to set. There might be the same subjects chosen multiple times.
std::vector<Genome> choosing_for_reproduction(Population& population, int number_of_chosen){

    std::uniform_real_distribution<double> distribution(0., 1.);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 generator(seed);

    std::vector<range> probabilities = array_of_probabilities(population.population);

    std::vector<Genome> chosen_genomes;

    std::vector<std::pair<int, Genome>> tournament;

    while (chosen_genomes.size() != number_of_chosen){

        double random_result = distribution(generator);

        for (int genome_rank = 0; genome_rank < probabilities.size(); genome_rank++){

            if (random_result >= probabilities[genome_rank].first && random_result < probabilities[genome_rank].second){

                tournament.emplace_back(genome_rank, population.population[genome_rank]);

                if (tournament.size() == 2){

                    int winner = tournament[0].first > tournament[1].first ? 0 : 1;

                    chosen_genomes.push_back(tournament[winner].second);
                    tournament.clear();
                }
                break;
            }
        }
    }

    return chosen_genomes;
}

void genetic_mod(std::vector<Genome> &reproduced, double mut_strength, double cross_possibility){

    std::uniform_real_distribution<double> distribution(0., 1.);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 generator(seed);


    std::uniform_int_distribution<int> distribution_int(0, reproduced.size() - 1);
    double prob_result;

    //TODO:
    //std::vector<Genome> offspring;

    int number_of_attempts = reproduced.size();

    for (int i = 0; i < number_of_attempts; i++){
        prob_result = distribution(generator);
        if (prob_result <= cross_possibility){

            int parent1 = distribution_int(generator);
            int parent2 = distribution_int(generator);

            reproduced.push_back(crossover(reproduced[parent1], reproduced[parent2]));

            //TODO:
            //offspring.push_back(crossover(reproduced[parent1], reproduced[parent2]));
        }
    }

    for (Genome &genome: reproduced){
        mutation(genome, mut_strength);
    }
}


//current is sorted, new is sorted
//succession set is elitism count best subjects from new_gen and then rest is best genomes from new_gen and current_gen
std::vector<Genome> succession(const std::vector<Genome>& current_gen, std::vector<Genome> &new_gen, int elitism_count) {
    std::vector<Genome> succession_result;

    succession_result.reserve(elitism_count);

    for (int i = 0; i < elitism_count; i++) {
        succession_result.push_back(current_gen[i]);
    }

    int population_size = current_gen.size();

    std::sort(new_gen.begin(), new_gen.end());

    for (int i = 0; i < population_size - elitism_count; i++){
        succession_result.push_back(new_gen[i]);
    }

    int k;
    return succession_result;
}

//evaluates the fitness of all genomes in population, using Bent Cigar Function (CEC 2017)
// f(x) = x1^2 + 10^6*sum{i >2}(xi^2)
void bent_cigar_fitness(std::vector<Genome> &current_population){
    for (int i=0; i<current_population.size(); i++){
        std::vector<double> current_gen = current_population[i].genome;

        double fitness_value_sum = current_gen[0]*current_gen[0];

        for (int j=1; j<current_gen.size(); j++)
            fitness_value_sum += 1000000*(current_gen[j]*current_gen[j]);

        current_population[i].fitness = fitness_value_sum;
    }
}
