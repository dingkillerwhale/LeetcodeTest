
#include "gaussian5x5.h"


void callGaussian5x5(double gKernel[][5], double sigma) {
	double r, s = 2.0 * sigma * sigma;
	double sum = 0.0;

	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			r = sqrt(i * i + j * j);
			gKernel[i + 2][j + 2] = (exp(-(r * r)/ s))/(PI * s);
			sum += gKernel[i + 2][j + 2];
		}
	}

	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 5; b++) {
			gKernel[a][b] /= sum;
		}
	}
}