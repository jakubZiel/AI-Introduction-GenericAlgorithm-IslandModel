//
// Created by jakub on 09.04.2021.
//
#include "std-algorithm/Evolution.h"
#include <iostream>
#include "island-model-algorithm/Island_model_evolution.h"
int main() {
    //generic config
    int pop_size = 100;
    int max_generations = 100;
    double cross_probapility = 0.5;
    double mutation_power = 1.2;
    int genome_length = 10;
    int func_num = 1;

    //island specific config
    int num_of_islands = 10;
    int subpopulation_size = 10;
    int num_of_migrations = 10;


    Evolution evo(pop_size, cross_probapility,mutation_power,genome_length);

    evo.run(2, max_generations, func_num);
    evo.show_best_std_fitness();
    std::cout << std::endl;

    Islands_Evolution ies(num_of_islands, subpopulation_size, cross_probapility, mutation_power, genome_length);
    ies.islands_evolution_run(2, max_generations, num_of_migrations, func_num);

    ies.show_best_archipelago_fitness();


     return 0;
}
