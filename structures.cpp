//
// Created by jakub on 25.03.2021.
//

#include "structures.h"


Genome::Genome() {
    fitness = 0;
}

Genome::Genome(int length) {
    fitness = 0;

    for (int i=0; i<length; i++){
        double d = generateRandDouble(-100.0, 100.0);
        genome.push_back(d);
    }
}

double Genome::generateRandDouble(double min, double max) {
    double d = (double)rand() / RAND_MAX;
    return min + d*(max - min);
}


Population::Population(int popSize, int genLength) {
    for (int i=0; i<popSize; i++){
        Genome newGenome = *new Genome(genLength);
        population.push_back(newGenome);
    }
}

