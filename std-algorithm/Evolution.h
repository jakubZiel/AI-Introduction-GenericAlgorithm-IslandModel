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

    Evolution(int population_size, double cross_probability, double mutation_power, int genome_length);
    void run(int elitism_count, int max_generations);

    void show_best_std_fitness();
};


#endif //PSZT_ISLAND_MODEL_EVOLUTION_H
