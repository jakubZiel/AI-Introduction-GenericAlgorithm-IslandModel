#include <iostream>
#include "structures/structures.h"
#include "std-algorithm/evolutionary_operations.h"



int main() {


    std::vector<Genome> gen;


    std::vector<std::pair<double, double>> res = array_of_probabilities(gen);

    for (std::pair<double, double>  prob : res) {
        std::cout << "[" << prob.first << "," << prob.second << "] ";
    }

    std::cout << std::endl;


    for (Genome &g : gen)
        std::cout << g << std::endl;
    return 0;
}
