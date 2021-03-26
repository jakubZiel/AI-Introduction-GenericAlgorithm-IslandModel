//
// Created by jakub on 25.03.2021.
//
#include "../structures/structures.h"
#include "../std-algorithm/evolutionary_operations.h"
int main() {

    Population pop(3,5);

    std::vector<std::pair<double, double>> res = array_of_probabilities(pop.population);

    return 0;
}