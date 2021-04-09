//
// Created by jakub on 27.03.2021.
//

#include "Evolution.h"
#include "evolutionary_operations.h"
#include <algorithm>
#include <iostream>
#include "CEC_2017/cec2017.h"

Evolution::Evolution(int pop_size, double cross_probability, double mutation_pwr, int gen_length) : population(pop_size, gen_length) {

    generation_count = 0;
    population_size = pop_size;
    cross_possibility = cross_probability;
    mutation_strength = mutation_pwr;
    genome_length = gen_length;
}

// performs evolution that last max_generations cycles
void Evolution::run(int elitism_count, int max_generations) {

    generation_count = 0;

    std::vector<Genome>* curr_population = &population.population;

    bent_cigar_fitness(*curr_population);

    std::sort(curr_population->begin(), curr_population->end());
    Genome best_genome = (*curr_population)[0];

    std::vector<Genome> reproduced_genomes;
    while (generation_count < max_generations){


        reproduced_genomes = choose_for_reproduction(population, population_size);
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

void Evolution::show_best_std_fitness() {
    std::cout << "std model evolution: " << this->population.population[0].fitness;
}
