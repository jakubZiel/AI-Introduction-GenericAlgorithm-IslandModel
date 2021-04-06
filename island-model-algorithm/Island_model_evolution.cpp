//
// Created by laura on 06.04.2021.
//

#include <structures/structures.h>
#include "Island_model_evolution.h"
#include <std-algorithm/Evolution.h>
#include <iostream>


void Islands_Evolution::migration_round(){

    std::vector<Genome> migrating;

    for (int i = 0; i<this->evolutions.size(); i++){

        std::vector<Genome> * curr_population = &evolutions[i].population.population;

        //populations are sorted, 5% best genomes migrate
        int num_of_migrating = 0.05 * (curr_population->size());
        if (num_of_migrating == 0)
            num_of_migrating = 1;


        migrating.insert(migrating.begin(), curr_population->begin(), curr_population->begin()+num_of_migrating);

        //migrating genomes are deleted from their original population
        curr_population->erase(curr_population->begin(), curr_population->begin()+num_of_migrating);

        //get onto the next island
        int next_island = (i+1)%evolutions.size();
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


void Islands_Evolution::islands_evolution_run(int elitism_count, int all_generations, int num_of_migrations) {

    int generations_between_migrations = all_generations / num_of_migrations;

    int migrations_done = 0;
    while (migrations_done < num_of_migrations){

        for (int j=0; j<this->evolutions.size(); j++){
            this->evolutions[j].run(elitism_count, generations_between_migrations);
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

    std::cout << min_fitness;

}
