//
// Created by jakub on 21.03.2021.
//
#include <utility>

#ifndef PSZT_ISLAND_MODEL_NEW_POPULATION_FACTORY_H
#define PSZT_ISLAND_MODEL_NEW_POPULATION_FACTORY_H

class Genome;
class Population;


std::pair<Genome,Genome> selection(Population actualPopulation);
std::pair<Genome,Genome> crossover(Genome par1, Genome par2);
Genome mutation(Genome genome);


#endif //PSZT_ISLAND_MODEL_NEW_POPULATION_FACTORY_H
