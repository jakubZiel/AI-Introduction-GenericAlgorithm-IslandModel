//
// Created by jakub on 08.04.2021.
//

#ifndef PSZT_ISLAND_MODEL_CEC2017_H
#define PSZT_ISLAND_MODEL_CEC2017_H
#include <vector>
#include <structures/structures.h>

void cec17_test_func(double *x, double *f, int nx, int mx,int func_num);

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


double *OShift,*M,*y,*z,*x_bound;
int ini_flag=0,n_flag,func_flag, *SS;



void free_cec_2017_adapter(double *population, double *fitness){

    free(population);
    free(fitness);
    free(y);
    free(z);
    free(M);
    free(OShift);
    free(x_bound);
    free(SS);
}

#endif //PSZT_ISLAND_MODEL_CEC2017_H
