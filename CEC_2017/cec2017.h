//
// Created by jakub on 08.04.2021.
//

#ifndef PSZT_ISLAND_MODEL_CEC2017_H
#define PSZT_ISLAND_MODEL_CEC2017_H
#include <vector>
#include <structures/structures.h>

void cec17_test_func(double *x, double *f, int nx, int mx,int func_num);

void cec_2017_adapter(double *x, double *f, std::vector<Genome> &population, int func_num);

void init_cec_2017_adapter( double *&population,  double *&fitness, int population_size, int dimensions);

void free_space(double *, double *);

void set_cec_fitness(std::vector<Genome> &population, int func_num);

#endif //PSZT_ISLAND_MODEL_CEC2017_H
