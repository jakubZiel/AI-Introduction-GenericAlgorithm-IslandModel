//
// Created by laura on 06.04.2021.
//

#ifndef PSZT_ISLAND_MODEL_ISLAND_MODEL_EVOLUTION_H
#define PSZT_ISLAND_MODEL_ISLAND_MODEL_EVOLUTION_H


#include <std-algorithm/Evolution.h>

class Islands_Evolution{
public:
    Islands_Evolution(int num_of_islands, int subpopulation_size, double cross_probability, double mutation_power, int genome_length);
    std::vector<Evolution> evolutions;

    void islands_evolution_run(int elitism_count, int all_generations, int num_of_migrations, int func_num);
    void migration_round();

    void show_best_archipelago_fitness();
    void run_cec_std(int elitism_count, int all_generations, int num_of_migrations, int func_num, int runs, double *errors);

    double get_best_from_archipelago();


    void record_best(double *errors, int curr_generation, int max_generations);
};




#endif //PSZT_ISLAND_MODEL_ISLAND_MODEL_EVOLUTION_H
