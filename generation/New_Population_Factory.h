//
// Created by jakub on 21.03.2021.
//

#ifndef PSZT_ISLAND_MODEL_NEW_POPULATION_FACTORY_H
#define PSZT_ISLAND_MODEL_NEW_POPULATION_FACTORY_H

#include <vector>

class Genome;
class Population;

std::vector<Genome> reproduction(Population& actualPopulation);

Genome mutation(const Genome& genome);

Genome crossover(Genome par1, Genome par2);

void genetic_mod(std::vector<Genome>& reproduced);

std::vector<Genome> succession();


#endif //PSZT_ISLAND_MODEL_NEW_POPULATION_FACTORY_H
