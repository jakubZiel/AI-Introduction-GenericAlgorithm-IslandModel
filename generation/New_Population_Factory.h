//
// Created by jakub on 21.03.2021.
//

#ifndef PSZT_ISLAND_MODEL_NEW_POPULATION_FACTORY_H
#define PSZT_ISLAND_MODEL_NEW_POPULATION_FACTORY_H

class Genome;
class Population;

int selection(Population& actualPopulation);
std::pair<Genome,Genome> crossover(Genome par1, Genome par2);
Genome mutation(const Genome& genome);


#endif //PSZT_ISLAND_MODEL_NEW_POPULATION_FACTORY_H
