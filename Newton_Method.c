#include "Newton_Method.h"

void Newton(double (*f)(double), double (*df)(double), double x0) {
	int itr = 10;
	int h = 0;
	double erro = 0.0001;
	double x1 = 0;
	for (int i = 0; i < itr; i++) {
		h = f(x0) / df(x0);
		x1 = x0 - h;
		printf("At iteration No.: %d    x = %9.6f\n", i, x1);
		if (fabs(h) < erro) {
			printf("Best Iteration at: %d \n Best root x = %9.6f\n", i, x1);
			return 0;
		}
		x0 = x1;
	}
	printf("No best solution\n");
}
double f(double x) {
	return pow(x,3) + pow(x,2) + 3;
}

double df(double x) {
	return 3 * pow(x, 2) + 2 * x;
}
