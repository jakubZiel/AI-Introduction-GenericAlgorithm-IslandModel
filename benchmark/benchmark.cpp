//
// Created by jakub on 14.04.2021.
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
                             int std_population_size, int func_num, int runs, int elitism){

    int run_counter = 0;
    auto* errors = new double[runs * 14];

    while (run_counter < runs){
        Evolution std_model(std_population_size, cross_probability, mutation_power, genome_length);

        record_errors(errors + run_counter * 14, std_model, func_num, elitism, max_generations);
        run_counter++;
    }

    double best, worst, mean, median;

    aggregate_data(errors, best, worst, mean, median, runs);

    print_aggregated_data(best, worst, mean ,median ,"standard");
    delete [] errors;
}


void generate_data_island_model(int max_generations, double cross_probability, double mutation_power, int genome_length,
                                int std_population_size, int num_of_islands, int subpopulation_size, int num_of_migrations, int func_num, int runs, int elitism){
    int run_counter = 0;
    auto* errors = new double[runs * 14];

    while (run_counter < runs){
        Islands_Evolution island_model(num_of_islands, subpopulation_size, cross_probability, mutation_power, genome_length);

        island_model.run_cec(elitism, max_generations, num_of_migrations, func_num, errors + run_counter * 14);

        run_counter++;
    }

    double best, worst, mean, median;

    aggregate_data(errors, best, worst, mean, median, runs);

    print_aggregated_data(best, worst, mean ,median ,"islands");

    delete [] errors;
}


double calc_mean(const double *errors, int size);

void record_errors(double *errors, Evolution &std_model, int func_num, int elitism, int max_generations){
    std_model.run(elitism, int(max_generations * 0.01), func_num);
    errors[0] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.01), func_num);
    errors[1] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.01), func_num);
    errors[2] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.02), func_num);
    errors[3] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.05), func_num);
    errors[4] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.1), func_num);
    errors[5] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.1), func_num);
    errors[6] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.1), func_num);
    errors[7] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.1), func_num);
    errors[8] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.1), func_num);
    errors[9] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.1), func_num);
    errors[10] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.1), func_num);
    errors[11] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.1), func_num);
    errors[12] = std_model.population.population[0].fitness;

    std_model.run(elitism, int(max_generations * 0.1), func_num);
    errors[13] = std_model.population.population[0].fitness;


}


void print_aggregated_data(double best, double worst, double mean, double median, const std::string& model){
    std::cout << std::setprecision(3)
              << "model : " << model << std::endl
              << "best : " << best << std::endl
              << "worst : " << worst << std::endl
              << "mean : " << mean << std::endl
              << "median : " << median << std::endl
              << std::endl << std::endl;

}

void aggregate_data(double *errors, double &best, double &worst, double &mean, double &median, int runs){
    std::sort(errors, errors + runs * 14);

    best = errors[0];
    worst = errors[runs * 14 - 1];
    mean = calc_mean(errors, runs * 14);
    median = runs % 2 == 1 ? errors[runs * 14 / 2] : (errors[runs * 14 / 2] + errors [runs * 14 / 2 - 1]) / 2;

}

double calc_mean(const double *errors, int size){

    double sum = 0.;
    for (int i = 0; i < size; i++)
        sum += errors[i];

    return sum / size;
}
#endif //PSZT_ISLAND_MODEL_BENCHMARK_H
