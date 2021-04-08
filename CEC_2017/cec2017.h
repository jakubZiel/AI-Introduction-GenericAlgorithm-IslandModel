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



#endif //PSZT_ISLAND_MODEL_CEC2017_H
