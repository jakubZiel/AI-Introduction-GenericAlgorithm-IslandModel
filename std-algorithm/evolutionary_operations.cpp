//
// Created by laura on 21.03.2021.
//
#include "evolutionary_operations.h"
#include "../structures/structures.h"
#include <chrono>
#include <cmath>
#include <algorithm>
#include <random>

typedef std::pair<double, double> range;

//basic mutation, as a driving force behind exploration
//it happens for every new genome chosen in choose_for_reproduction()
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
    std::uniform_real_distribution<double> distribution(0,1);
    Genome child;

    double weight = std::abs(distribution(generator));

    double crossed_gene;

    for (int i = 0; i < par1.genome.size(); i++){

        crossed_gene = weight * par1.genome[i] + (1 - weight) * par2.genome[i];
        child.genome.push_back(crossed_gene);
    }

    return child;
}

//value that represents probability of being chosen for tournament
double rank_value(int rank, int population_size){
    auto mi = (double)population_size;

    return (-2 * rank + 1. + 2. * mi ) / std::pow(mi, 2);
}

//building array of probabilities for sorted population
// array_of_probabilities models probability distribution of being chosen for tournament
//  0 ====>  |        1st best        |      2nd      |    3rd    |  4th  |  5th  | 6th |  <====  1

std::vector<range> array_of_probabilities(const std::vector<Genome> &genomes) {
    std::vector<range> probabilities;
    double current = 0.0;
    range curr_range;

    for (int i = 0; i < genomes.size(); i++) {
        curr_range.first = current;
        curr_range.second = current = current + rank_value(i + 1, genomes.size());

        probabilities.push_back(curr_range);
    }

    //normalize to range 0 - 1

    for (range &r : probabilities) {
        r.first /= probabilities[probabilities.size() - 1].second;
        r.second /= probabilities[probabilities.size() - 1].second;
    }
    return probabilities;
}


std::vector<Genome> choose_for_reproduction(Population& population, int number_of_chosen){

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 generator(seed);

    std::vector<Genome> chosen_genomes;


    std::uniform_int_distribution<int> distribution_int(0, population.population.size() - 1);

    int first, second, winner;

    while (chosen_genomes.size() != number_of_chosen){

        first = distribution_int(generator);
        second = distribution_int(generator);

        winner = population.population[first] < population.population[second] ? first : second;

        chosen_genomes.push_back(population.population[winner]);

    }
    return chosen_genomes;
}

//perform mutation and crossing operation on population
void genetic_mod(std::vector<Genome> &reproduced, double mut_strength, double cross_possibility){

    std::uniform_real_distribution<double> distribution(0., 1.);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 generator(seed);


    std::uniform_int_distribution<int> distribution_int(0, reproduced.size() - 1);
    double prob_result;


    int partner;

    for (int curr_genome = 0; curr_genome < reproduced.size(); curr_genome++){
        prob_result = distribution(generator);

        if (prob_result <= cross_possibility){
            partner = distribution_int(generator);

            Genome child = crossover(reproduced[curr_genome], reproduced[partner]);
            reproduced.at(curr_genome) = child;
        }
    }


    for (Genome &genome: reproduced){
        mutation(genome, mut_strength);
    }

}


//current should be sorted, new should be sorted
//succession set is elitism count best subjects from current_gen and then rest is the best genomes from new_gen
std::vector<Genome> succession(const std::vector<Genome>& current_gen, std::vector<Genome> &new_gen, int elitism_count) {
    std::vector<Genome> succession_result;

    succession_result.reserve(elitism_count);

    for (int i = 0; i < elitism_count; i++) {
        succession_result.push_back(current_gen[i]);
    }

    int population_size = current_gen.size();


    for (int i = 0; i < population_size - elitism_count; i++){
        succession_result.push_back(new_gen[i]);
    }

    return succession_result;
}

//evaluates the fitness of all genomes in population, using Bent Cigar Function (CEC_2017)
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
