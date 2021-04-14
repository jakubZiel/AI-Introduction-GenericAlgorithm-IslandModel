//
// Created by laura on 06.04.2021.
//

#include <structures/structures.h>
#include "Island_model_evolution.h"
#include <std-algorithm/Evolution.h>
#include <iostream>
#include <algorithm>
#include "CEC_2017/cec2017.h"
#include "std-algorithm/evolutionary_operations.h"

void Islands_Evolution::migration_round(){

    std::vector<Genome> migrating;

    for (int i = 0; i<this->evolutions.size(); i++){

        std::vector<Genome> * curr_population = &evolutions[i].population.population;

        //populations are sorted, 10% best genomes migrate
        int num_of_migrating = int(0.1 * curr_population->size());
        if (num_of_migrating == 0)
            num_of_migrating = 1;


        migrating.insert(migrating.begin(), curr_population->begin(), curr_population->begin()+num_of_migrating);

        //migrating genomes are deleted from their original population
        curr_population->erase(curr_population->begin(), curr_population->begin()+num_of_migrating);

        //get onto the next island
        int next_island = (i+1) % int(evolutions.size());
        curr_population = &evolutions[next_island].population.population;

        curr_population->insert(curr_population->end(), migrating.begin(), migrating.end());

        migrating.clear();
    }
}

Islands_Evolution::Islands_Evolution(int num_of_islands, int subpopulation_size, double cross_probability, double mutation_power, int genome_length){

    for (int i=0; i< num_of_islands; i++){
        Evolution newEvolution = *new Evolution(subpopulation_size, cross_probability, mutation_power, genome_length);
        evolutions.push_back(newEvolution);
    }
}


void Islands_Evolution::islands_evolution_run(int elitism_count, int all_generations, int num_of_migrations, int func_num) {

    int generations_between_migrations = all_generations / num_of_migrations;

    int migrations_done = 0;
    while (migrations_done < num_of_migrations){

        for (int j=0; j<this->evolutions.size(); j++){
            this->evolutions[j].run(elitism_count, generations_between_migrations, func_num);
        }

        migration_round();
        migrations_done++;
    }

}


void Islands_Evolution::show_best_archipelago_fitness() {

    double min_fitness = this->evolutions[0].population.population[0].fitness;

    for (int i=0; i<this->evolutions.size(); i++){
        Population * curr_island_population = &(this->evolutions[i].population);
        min_fitness = std::min(min_fitness, curr_island_population->population[0].fitness);
    }

    std::cout <<"isl model evolution: " << min_fitness;
}


double Islands_Evolution::get_best_from_archipelago(){
    std::sort(evolutions.begin(), evolutions.end(),[](Evolution &e1, Evolution &e2){ return e1.population.population[0] < e2.population.population[0];});
    return evolutions[0].population.population[0].fitness;
}

Genome Islands_Evolution::get_best_from_archipelago_ref(){
    std::sort(evolutions.begin(), evolutions.end(),[](Evolution &e1, Evolution &e2){ return e1.population.population[0] < e2.population.population[0];});
    return evolutions[0].population.population[0];
}


//TODO:
void Islands_Evolution::run_cec(int elitism_count, int all_generations, int num_of_migrations, int func_num, double *errors) {

    int generation_counter = 0;

    std::vector<Genome> *curr_population;

    double mutation_strength = evolutions[0].mutation_strength;
    double cross_probability = evolutions[0].cross_possibility;


    for (Evolution &e : evolutions) {

        curr_population = &e.population.population;
        set_cec_fitness(*curr_population, func_num);
        std::sort(curr_population->begin(), curr_population->end());
    }

    Genome best_in_archipelago = get_best_from_archipelago_ref();

    while (generation_counter < all_generations){

        for (Evolution &e : evolutions){
            std::vector<Genome> reproduced_genomes;
            curr_population = &e.population.population;

            reproduced_genomes = choose_for_reproduction(e.population, curr_population->size());
            genetic_mod(reproduced_genomes, mutation_strength, cross_probability);

            set_cec_fitness(reproduced_genomes, func_num);
            std::sort(reproduced_genomes.begin(), reproduced_genomes.end());

            *curr_population = succession(*curr_population, reproduced_genomes, elitism_count);

            std::sort(curr_population->begin(), curr_population->end());
        }

        Genome current_best = get_best_from_archipelago_ref();

        if (current_best < best_in_archipelago){
            best_in_archipelago = current_best;
        }

        int generation_cycle = all_generations / num_of_migrations;

        if (generation_counter % generation_cycle == 0 && generation_counter !=0)
            migration_round();

        record_best(errors, generation_counter, all_generations);

        generation_counter++;
    }

    double best = get_best_from_archipelago();

    show_best_archipelago_fitness();
}



void Islands_Evolution::record_best(double *errors, int curr_generation, int max_generations){

    if (max_generations * 0.01 == curr_generation )
        errors[0] = get_best_from_archipelago();

    if (max_generations * 0.02 == curr_generation )
        errors[1] = get_best_from_archipelago();

    if (max_generations * 0.03 == curr_generation )
        errors[2] = get_best_from_archipelago();

    if (max_generations * 0.05 == curr_generation )
        errors[3] = get_best_from_archipelago();

    if (max_generations * 0.1 == curr_generation )
        errors[4] = get_best_from_archipelago();

    if (max_generations * 0.2 == curr_generation )
        errors[5] = get_best_from_archipelago();

    if (max_generations * 0.3 == curr_generation )
        errors[6] = get_best_from_archipelago();

    if (max_generations * 0.4 == curr_generation )
        errors[7] = get_best_from_archipelago();

    if (max_generations * 0.5 == curr_generation )
        errors[8] = get_best_from_archipelago();

    if (max_generations * 0.6 == curr_generation )
        errors[9] = get_best_from_archipelago();

    if (max_generations * 0.7 == curr_generation )
        errors[10] = get_best_from_archipelago();

    if (max_generations * 0.8 == curr_generation )
        errors[11] = get_best_from_archipelago();

    if (max_generations * 0.9 == curr_generation )
        errors[12] = get_best_from_archipelago();

    if (max_generations - 1 == curr_generation )
        errors[13] = get_best_from_archipelago();

}