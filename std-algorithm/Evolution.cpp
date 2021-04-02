//
// Created by jakub on 27.03.2021.
//

#include "Evolution.h"
#include "evolutionary_operations.h"
#include <algorithm>

Evolution::Evolution(int pop_size, double cross_prob, double mutation_pwr, int gen_length, int max_gens) : population(pop_size, gen_length) {

    generation_count = 0;
    max_generations = max_gens;
    population_size = pop_size;
    cross_possibility = cross_prob;
    mutation_strength = mutation_pwr;
    genome_length = gen_length;
}

void Evolution::run(double reproducing_fraction, int elitism_count) {


}
