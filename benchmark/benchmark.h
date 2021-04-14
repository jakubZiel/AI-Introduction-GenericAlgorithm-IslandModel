//
// Created by jakub on 13.04.2021.
//

#ifndef PSZT_ISLAND_MODEL_BENCHMARK_H
#define PSZT_ISLAND_MODEL_BENCHMARK_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include "std-algorithm/Evolution.h"
#include "island-model-algorithm/Island_model_evolution.h"

void record_errors(double *errors, Evolution &std_model, int func_num, int elitism, int max_generations);

void aggregate_data(double *errors, double &best, double &worst, double &mean, double &median, int runs);

void print_aggregated_data(double best, double worst, double mean, double median, const std::string& model);

void generate_data_std_model(int max_generations, double cross_probability, double mutation_power, int genome_length,
                   int std_population_size, int func_num, int runs, int elitism);

void generate_data_island_model(int max_generations, double cross_probability, double mutation_power, int genome_length,
                                int std_population_size, int num_of_islands, int subpopulation_size, int num_of_migrations, int func_num, int runs, int elitism);


double calc_mean(const double *errors, int size);




#endif //PSZT_ISLAND_MODEL_BENCHMARK_H
