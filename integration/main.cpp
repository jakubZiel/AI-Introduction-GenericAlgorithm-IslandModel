//
// Created by laura on 09.04.2021.
//
#include "std-algorithm/Evolution.h"
#include <iostream>
#include "island-model-algorithm/Island_model_evolution.h"
#include "benchmark/benchmark.h"

void general_test(int max_generations, double cross_probability, double mutation_power, int genome_length,
                  int std_population_size, int num_of_islands, int subpopulation_size, int num_of_migrations, int func_num){

    Evolution evo(std_population_size, cross_probability, mutation_power, genome_length);

    evo.run(2, max_generations, func_num);
    evo.show_best_std_fitness();
    std::cout << std::endl;

    Islands_Evolution ies(num_of_islands, subpopulation_size, cross_probability, mutation_power, genome_length);
    ies.islands_evolution_run(2, max_generations, num_of_migrations, func_num);

    ies.show_best_archipelago_fitness();

}

void test_population_size(int std_population_size, int num_of_islands, int subpopulation_size, int func_num){

    //generic config
    int max_generations = 10000;
    double cross_probability = 0.5;
    double mutation_power = 1.2;
    int genome_length = 10;

    //island specific config
    int num_of_migrations = 10;

    std::cout << "Test: population sizes" << std::endl;

    general_test(max_generations, cross_probability, mutation_power, genome_length, std_population_size,
                 num_of_islands, subpopulation_size, num_of_migrations, func_num);

    std::cout << std::endl << std::endl;

}

void test_max_generations(int max_generations, int func_num){

    //generic config
    int std_population_size = 100;
    double cross_probability = 0.5;
    double mutation_power = 1.2;
    int genome_length = 10;

    //island specific config
    int num_of_islands = 10;
    int subpopulation_size = 10;
    int num_of_migrations = 10;


    std::cout << "Test: maximum number of generations" << std::endl;

    general_test(max_generations, cross_probability, mutation_power, genome_length, std_population_size,
                 num_of_islands, subpopulation_size, num_of_migrations, func_num);

    std::cout << std::endl << std::endl;
}

void test_num_of_migrations(int num_of_migrations, int func_num){

    //generic config
    int max_generations = 100;
    int std_population_size = 100;
    double cross_probability = 0.5;
    double mutation_power = 1.2;
    int genome_length = 10;

    //island specific config
    int num_of_islands = 10;
    int subpopulation_size = 10;


    std::cout << "Test: number of migrations" << std::endl;

    general_test(max_generations, cross_probability, mutation_power, genome_length, std_population_size,
                 num_of_islands, subpopulation_size, num_of_migrations, func_num);

    std::cout << std::endl << std::endl;
}


int main() {

    generate_data_std_model(200, 0.5, 1.5, 10, 100, 1, 10, 2);

    generate_data_island_model(200, 0.5, 1.5, 10, 100, 10, 10, 10, 1, 10, 2 );

    return 0;
}
