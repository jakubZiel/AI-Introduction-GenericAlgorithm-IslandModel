//
// Created by jakub on 25.03.2021.
//
#include <iostream>
#include "std-algorithm/Evolution.h"
#include "island-model-algorithm/Island_model_evolution.h"



int main() {

   Evolution evo(1000, 0.5,1,10);

   evo.run(1, 1000, 1);
   evo.show_best_std_fitness();
   std::cout << std::endl;


    Islands_Evolution ies(10, 100, 0.5, 1, 10);
    ies.islands_evolution_run(1, 1000, 10, -1);

    ies.show_best_archipelago_fitness();
    return 0;
}