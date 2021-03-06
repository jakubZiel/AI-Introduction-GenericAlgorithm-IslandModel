//
// Created by jakub on 27.03.2021.
//

#include "CEC_API/cec2017.h"
#include "Evolution.h"
#include "evolutionary_operations.h"
#include <algorithm>


Evolution::Evolution(int pop_size, double cross_probability, double mutation_pwr, int gen_length) : population(pop_size, gen_length) {

    generation_count = 0;
    population_size = pop_size;
    cross_possibility = cross_probability;
    mutation_strength = mutation_pwr;
    genome_length = gen_length;
}

// performs evolution that last max_generations cycles
void Evolution::run(int elitism_count, int max_generations, int func_num) {

    generation_count = 0;

    std::vector<Genome>* curr_population = &population.population;

    set_cec_fitness(*curr_population, func_num);

    std::sort(curr_population->begin(), curr_population->end());
    Genome best_genome = (*curr_population)[0];
    std::vector<Genome> reproduced_genomes;

    while (generation_count < max_generations){


        reproduced_genomes = choose_for_reproduction(population, population_size);
        genetic_mod(reproduced_genomes, mutation_strength, cross_possibility);

        set_cec_fitness(reproduced_genomes, func_num);

        std::sort(reproduced_genomes.begin(), reproduced_genomes.end());

        if (best_genome > reproduced_genomes[0]){
            best_genome = reproduced_genomes[0];
        }

        *curr_population = succession(*curr_population, reproduced_genomes, elitism_count);
        generation_count++;
    }

    std::sort(curr_population->begin(), curr_population->end());
}
