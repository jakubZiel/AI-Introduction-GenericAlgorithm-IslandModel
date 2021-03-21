//
// Created by jakub on 21.03.2021.
//
#include <utility>
#include "New_Population_Factory.h"
#include "../structures.h"

typedef std::pair<Genome,Genome> Pair;

Genome mutation(const Genome& par1){
    Genome genome;
    return genome;
}

Pair crossover(const Genome& par1, const Genome& par2){
    Pair pair;

    return  pair;
}

Genome& selection(Population& population){

    return population.population[0];
}
