//
// Created by jakub on 21.03.2021.
//

#ifndef PSZT_ISLAND_MODEL_STRUCTURES_H
#define PSZT_ISLAND_MODEL_STRUCTURES_H
#include <vector>


class Genome{
public:
    std::vector<double> genome;
};

class Population{
public:
    std::vector<Genome> population;
};

#endif //PSZT_ISLAND_MODEL_STRUCTURES_H
