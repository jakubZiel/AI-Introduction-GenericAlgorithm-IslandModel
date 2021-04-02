//
// Created by jakub on 21.03.2021.
//

#ifndef PSZT_ISLAND_MODEL_EVOLUTIONARY_OPERATIONS_H
#define PSZT_ISLAND_MODEL_EVOLUTIONARY_OPERATIONS_H

#include <vector>
#include <utility>

class Genome;
class Population;

std::vector<Genome> choosing_for_reproduction(Population& population, int number_of_chosen);

void mutation(Genome& genome, double mut_strength);

Genome crossover(const Genome& par1, const Genome& par2);

void genetic_mod(std::vector<Genome> &reproduced, double mut_strength, double cross_possibility);

std::vector<Genome> succession(const std::vector<Genome>& current_gen, const std::vector<Genome> &new_gen, int elitism_count);

std::vector<std::pair<double, double>> array_of_probabilities(const std::vector<Genome> &genomes);

void bent_cigar_fitness(std::vector<Genome> &current_population);

#endif //PSZT_ISLAND_MODEL_EVOLUTIONARY_OPERATIONS_H
