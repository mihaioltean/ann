// ann.cpp : Defines the entry point for the console application.
//

#include "ann.h"
#include <stdio.h>
#include "read_data.h"

t_ann ann;

//---------------------------------------------------------------------------
void f(void)
{
	//printf("epoch = %d error = %lf\n", ann.get_epoch(), ann.get_error());
	printf("epoch = %d error = %lf num_incorrect_class = %d\n", ann.get_epoch(), ann.get_error(), ann.get_num_incorrectly_classified());
	char filename[100];
	sprintf(filename, "ann_%d.js", ann.get_epoch());
	ann.to_js(filename);
}
//------------------------------------------------------------------------
int main()
{
	double **training_data;
	double **target;
	int num_data;

	int num_variables;
	int num_outputs;

	printf("reading data ... ");
	if (!read_file("c:/Mihai/uab/ann/data/mnist_train.txt", training_data, target, num_data, num_variables, num_outputs)) {
		printf("Cannot read file!\n");
		getchar();
		return 1;
	}
	
	printf("done\n");
		
		ann.set_num_layers(3);
		ann.set_num_neurons(0, num_variables);
		ann.set_num_neurons(1, 100);
		ann.set_num_neurons(2, num_outputs);

		ann.set_learning_rate(0.01);
		ann.set_num_iterations(100);

		ann.train(training_data, target, num_data, f);
		
		double error = ann.get_error();
		ann.to_file("ann.txt");
		ann.to_js("ann.js");
		
	printf("Error = %lf\n", error);

	delete_data(training_data, target, num_data);

	ann.release_memory();

	printf("Press Enter to terminate...\n");

	getchar();

    return 0;
}
//------------------------------------------------------------------------