//
// Created by jakub on 25.03.2021.
//
#include <iostream>
#include "std-algorithm/Evolution.h"
#include "island-model-algorithm/island_model_evolution.h"


int main() {

   Evolution evo(50, 0.3,1.5,5);

   evo.run(2, 50);
   evo.show_best_std_fitness();
   std::cout << std::endl;


    Islands_Evolution ies(5, 10, 0.3, 1.5, 5);
    ies.islands_evolution_run(2, 20, 4);

    ies.show_best_archipelago_fitness();

    return 0;
}