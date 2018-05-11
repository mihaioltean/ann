// ann.cpp : Defines the entry point for the console application.
//

#include "ann.h"

int main()
{
	t_ann ann;
	ann.set_num_layers(3);
	ann.set_num_neurons(0, 784);
	ann.set_num_neurons(1, 100);
	ann.set_num_neurons(2, 10);

	ann.set_num_iterations(100000);

	double **training_data;
	double **target;
	int num_data;

	read_file(training_data, target, num_data);

	ann.train(training_data, target, num_data);

	double error = ann.get_error();

	printf("Error = %lf\n", error);

	getchar();

    return 0;
}

