#include <stdio.h>
#include <stdbool.h> // define boolean type

bool isMonotonic(int* A, int ASize) {

	int flag = 2;
	if (ASize <= 2) {
		return true;
	}
	else {
		for (int i = 1; i<ASize; i++) {
			if (A[i - 1] != A[i]) {
				if (flag == 2)
					flag = (A[i - 1]>A[i]) * 1;
				if (((A[i - 1]<A[i]) && (flag == 1)) || ((A[i - 1]>A[i]) && (flag == 0)))
					return false;
			}

		}
	}

	return true;

}