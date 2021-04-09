/*
  CEC17 Test Function Suite for Single Objective Optimization
  Noor Awad (email: noor0029@ntu.edu.sg) 
  Sep. 10th 2016
*/

#include "cec2017.h"
#include <algorithm>




int main()
{
	int dimensions, population_size;
	double *f,*x;
	dimensions=10;
	population_size=12;

	init_cec_2017_adapter(x,f,population_size, dimensions);

	std::vector<Genome> pop;

    Genome g = Genome(10);
    Genome g1 = Genome(10);
    Genome g2 = Genome(10);
    Genome g3 = Genome(10);

    pop.push_back(g);
    pop.push_back(g1);
    pop.push_back(g2);
    pop.push_back(g3);
    pop.push_back(g);
    pop.push_back(g1);
    pop.push_back(g2);
    pop.push_back(g3);
    pop.push_back(g);
    pop.push_back(g1);
    pop.push_back(g2);
    pop.push_back(g3);


	cec_2017_adapter(x,f,pop,1);

	std::sort(pop.begin(), pop.end());

    free_cec_2017_adapter(x, f);
}


