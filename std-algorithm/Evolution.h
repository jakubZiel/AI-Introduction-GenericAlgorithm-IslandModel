//
// Created by jakub on 27.03.2021.
//

#ifndef PSZT_ISLAND_MODEL_EVOLUTION_H
#define PSZT_ISLAND_MODEL_EVOLUTION_H

#include <structures/structures.h>

class Evolution {
public:
    int generation_count;
    Population population;

    double cross_possibility;
    double mutation_strength;
    int population_size;
    int genome_length;
    int max_generations;

    Evolution(int population_size, double cross_probapility, double mutation_power, int genome_length, int max_generations);
    void run(double reproducing_fraction, int elitism_count);
};


#endif //PSZT_ISLAND_MODEL_EVOLUTION_H
