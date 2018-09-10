#include "gaussian5x5.h"

int main(int argv, char *argc) {
	double Kernel[5][5];
	double sigma = 1.0;

	callGaussian5x5(Kernel, sigma);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%.4f  ", Kernel[i][j]);
		}
		printf("\n");
	}
	return 0;

}