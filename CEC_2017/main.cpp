/*
  CEC17 Test Function Suite for Single Objective Optimization
  Noor Awad (email: noor0029@ntu.edu.sg) 
  Sep. 10th 2016
*/

#include "cec2017.h"


double *OShift,*M,*y,*z,*x_bound;
int ini_flag=0,n_flag,func_flag,*SS;


int main()
{
	int dimensions, population_size;
	double *f,*x;
	dimensions=10;
	population_size=4;

	init_cec_2017_adapter(x,f,population_size, dimensions);

	std::vector<Genome> pop;

    Genome g = Genome(10);
    pop.push_back(g);
    pop.push_back(g);
    pop.push_back(g);
    pop.push_back(g);

	cec_2017_adapter(x,f,pop,1);

	free(x);
	free(f);
	free(y);
	free(z);
	free(M);
	free(OShift);
	free(x_bound);
}


