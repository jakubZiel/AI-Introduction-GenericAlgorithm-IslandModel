//
// Created by jakub on 27.03.2021.
//

#include "Evolution.h"
#include "evolutionary_operations.h"
#include <algorithm>

Evolution::Evolution(int pop_size, double cross_prob, double mutation_pwr, int gen_length, int max_gens) : population(pop_size, gen_length) {

    generation_count = 0;
    max_generations = max_gens;
    population_size = pop_size;
    cross_possibility = cross_prob;
    mutation_strength = mutation_pwr;
    genome_length = gen_length;
}

void Evolution::run(double reproducing_fraction, int elitism_count) {

    generation_count = 0;

    std::vector<Genome>* curr_population = &population.population;

    bent_cigar_fitness(*curr_population);

    std::sort(curr_population->begin(), curr_population->end());
    Genome best_genome = (*curr_population)[0];

    std::vector<Genome> reproduced_genomes;
    while (generation_count < max_generations){


        reproduced_genomes = choosing_for_reproduction(population, int(population_size * reproducing_fraction));
        genetic_mod(reproduced_genomes, mutation_strength, cross_possibility);

        bent_cigar_fitness(reproduced_genomes);
        std::sort(reproduced_genomes.begin(), reproduced_genomes.end());

        if (best_genome > reproduced_genomes[0]){
            best_genome = reproduced_genomes[0];
        }

        *curr_population = succession(*curr_population, reproduced_genomes, elitism_count);
        generation_count++;
    }

    bent_cigar_fitness(*curr_population);
    std::sort(curr_population->begin(), curr_population->end());
}