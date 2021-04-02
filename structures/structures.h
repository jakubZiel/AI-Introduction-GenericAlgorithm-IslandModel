//
// Created by jakub on 21.03.2021.
//

#ifndef PSZT_ISLAND_MODEL_STRUCTURES_H
#define PSZT_ISLAND_MODEL_STRUCTURES_H
#include <vector>
#include <ostream>

class Genome{

public:
    std::vector<double> genome;
    double fitness;

    explicit Genome(int length);

    Genome();

    bool operator<(const Genome& other_genome) const;
    bool operator>(const Genome &other_genome) const;

    static double generateRandDouble(double min, double max);
    friend std::ostream &operator<<(std::ostream &out, const Genome& genome);
    };

class Population{
public:
    std::vector<Genome> population;
    
    Population(int pop_size, int gen_length);
};

#endif //PSZT_ISLAND_MODEL_STRUCTURES_H
