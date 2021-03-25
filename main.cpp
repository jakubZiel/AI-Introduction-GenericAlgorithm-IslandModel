#include <iostream>
#include "structures.h"
#include "generation/New_Population_Factory.h"



int main() {


    std::vector<Genome> gen;
    gen.emplace_back();
    gen.emplace_back();
    gen.emplace_back();



    std::vector<std::pair<double, double>> res = array_of_probabilities(gen);

    for (std::pair<double, double>  prob : res) {
        std::cout << "[" << prob.first << "," << prob.second << "] ";
    }
    return 0;
}
