//
// Created by jakub on 13.04.2021.
//
#include <vector>
#include <structures/structures.h>
#include "CEC_2017/cec2017.h"


double *OShift,*M,*y,*z,*x_bound;
int ini_flag,n_flag,func_flag, *SS;


void cec_2017_adapter(double *x, double *f, std::vector<Genome> &population, int func_num){

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

