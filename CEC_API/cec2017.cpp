//
// Created by jakub on 13.04.2021.
//
#include <vector>
#include <structures/structures.h>
#include "cec2017.h"
#include "std-algorithm/evolutionary_operations.h"

double *OShift,*M,*y,*z,*x_bound;
int ini_flag,n_flag,func_flag, *SS;


void cec_2017_adapter(double *x, double *f, std::vector<Genome> &population, int func_num){

    if (func_num == 2){
        bent_cigar_fitness(population);
        return;
    }

    int ptr = 0;

    for (auto & i : population){

        std::vector<double>* genome = &i.genome;

        for (double j : *genome){

            x[ptr] = j;
            ptr++;
        }
    }

    cec17_test_func(x,f,population[0].genome.size(),population.size(), func_num);

    for (int i = 0; i < population.size(); i++){

        population[i].fitness = f[i];
    }
}

void init_cec_2017_adapter( double *&population,  double *&fitness, int population_size, int dimensions){
    population = (double *)malloc(dimensions * population_size * sizeof(double));
    fitness = (double *)malloc(sizeof(double)  *  population_size);
}


void free_space(double *pop, double *fit){
    delete [] pop;
    delete [] fit;
}

void set_cec_fitness(std::vector<Genome> &population, int func_num){
    double *population_ptr, *fitness_ptr;
    int dimensions = population[0].genome.size();
    int population_size = population.size();

    init_cec_2017_adapter(population_ptr, fitness_ptr, population_size, dimensions);
    cec_2017_adapter(population_ptr, fitness_ptr, population, func_num);
    free_space(population_ptr, fitness_ptr);

}