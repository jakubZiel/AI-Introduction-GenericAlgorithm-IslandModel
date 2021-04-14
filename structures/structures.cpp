//
// Created by laura on 25.03.2021.
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

bool Genome::operator<(const Genome &other_genome) const {
    return fitness < other_genome.fitness;
}

bool Genome::operator> (const Genome &other_genome) const {
    return fitness > other_genome.fitness;
}

std::ostream &operator<<(std::ostream &out, const Genome& genome){

    out << "Genome: ";
    for (double i : genome.genome){
        out << i << ", ";
    }

    out << "fitness: "<< genome.fitness;
    return out;
}

Population::Population(int popSize, int genLength) {
    for (int i=0; i<popSize; i++){
        Genome newGenome = *new Genome(genLength);
        population.push_back(newGenome);
    }
}


