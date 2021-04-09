//
// Created by jakub on 09.04.2021.
//

//
// Created by jakub on 27.03.2021.
//

#include "std-algorithm/Evolution.h"
#include "std-algorithm/evolutionary_operations.h"
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

    int func_num = 1;

    generation_count = 0;

    std::vector<Genome>* curr_population = &population.population;

    int dimensions = population.population[0].genome.size();
    double *population_ptr, *fitness_ptr;

    init_cec_2017_adapter(population_ptr, fitness_ptr, population_size, dimensions);
    cec_2017_adapter(population_ptr, fitness_ptr, *curr_population, func_num);

    std::sort(curr_population->begin(), curr_population->end());
    Genome best_genome = (*curr_population)[0];

    std::vector<Genome> reproduced_genomes;
    while (generation_count < max_generations){


        reproduced_genomes = choose_for_reproduction(population, population_size);
        genetic_mod(reproduced_genomes, mutation_strength, cross_possibility);

        init_cec_2017_adapter(population_ptr, fitness_ptr, reproduced_genomes.size(), dimensions);
        cec_2017_adapter(population_ptr, fitness_ptr, reproduced_genomes, func_num);

        std::sort(reproduced_genomes.begin(), reproduced_genomes.end());

        if (best_genome > reproduced_genomes[0]){
            best_genome = reproduced_genomes[0];
        }

        *curr_population = succession(*curr_population, reproduced_genomes, elitism_count);
        generation_count++;
    }


    init_cec_2017_adapter(population_ptr, fitness_ptr, population_size, dimensions);
    cec_2017_adapter(population_ptr, fitness_ptr, *curr_population, func_num);

    std::sort(curr_population->begin(), curr_population->end());
}

void Evolution::show_best_std_fitness() {
    std::cout << "std model evolution: " << this->population.population[0].fitness;
}
