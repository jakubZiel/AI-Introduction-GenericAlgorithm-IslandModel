//
// Created by laura on 09.04.2021.
//
#include <iostream>
#include "benchmark/benchmark.h"




int main() {

    int func_num = 1;
    std::cout << "func : " << func_num << std::endl << std::endl;

    int max_generations = 200;
    double mutation_strength = 1.2;
    double cross_probability = 0.5;
    int genome_length = 10;
    int pop_size = 200;
    int runs = 25;
    int elitism = 2;

    std::cout
    << "max gens : " << max_generations
    << " | cross_prob : " << cross_probability
    << " | mut_strength : " << mutation_strength
    << " | pop_size : " << pop_size
    << " | dimensions : " << genome_length
    << " | runs :  " << runs
    << " | elitism : " << elitism
    << std::endl << std::endl;

    generate_data_std_model(max_generations, cross_probability, mutation_strength, genome_length, pop_size, func_num, 25, 2);

    std::cout << "num of islands : 20, 10, 5 ,4 ,2 (max pop = " << pop_size << ")" << std::endl << std::endl;

    generate_data_island_model(max_generations, cross_probability, mutation_strength, genome_length, pop_size, 20, 10, 10, func_num, 25, 2 );
    generate_data_island_model(max_generations, cross_probability, mutation_strength, genome_length, pop_size, 10, 20, 10, func_num, 25, 2 );
    generate_data_island_model(max_generations, cross_probability, mutation_strength, genome_length, pop_size, 5, 40, 10, func_num, 25, 2 );
    generate_data_island_model(max_generations, cross_probability, mutation_strength, genome_length, pop_size, 4, 50, 10, func_num, 25, 2 );
    generate_data_island_model(max_generations, cross_probability, mutation_strength, genome_length, pop_size, 2, 100, 10, func_num, 25, 2 );

    return 0;
}
