//
// Created by laura on 06.04.2021.
//

#ifndef PSZT_ISLAND_MODEL_ISLAND_MODEL_EVOLUTION_H
#define PSZT_ISLAND_MODEL_ISLAND_MODEL_EVOLUTION_H


#include <std-algorithm/Evolution.h>

class Islands_Evolution{
public:
    Islands_Evolution(int num_of_islands, int subpopulation_size, double cross_probapility, double mutation_power, int genome_length);
    std::vector<Evolution> evolutions;

    void islands_evolution_run(int elitism_count, int all_generations, int migration_frequency);
    void migration_round();
};




#endif //PSZT_ISLAND_MODEL_ISLAND_MODEL_EVOLUTION_H
