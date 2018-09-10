#include <stdio.h>


void QuickSort(int* arry, int left, int right) {
	int i =left, j =right, pivot, temp;
	
	if (left < right) { // when the array size is larger than 1, then it starts
		pivot = left; // choose the first element as the pivot
		i = left;
		j = right;

		while (i < j) {
			while (i < right && arry[i] <= arry[pivot]) // find the one bigger than pivot
				i++;
			while (arry[j] > arry[pivot]) // find the one not bigger than pivot
				j--;
			if (i < j) { // swap the value before they meet
				temp = arry[i];
				arry[i] = arry[j];
				arry[j] = temp;
			}
		}
		// since pivot starts from far left, swap pivot with the last one not bigger than pivot.
		temp = arry[pivot];
		arry[pivot] = arry[j];
		arry[j] = temp;
		// After that, left side of pivot are all no bigger than pivot
		// and right side are all bigger than pivot
		QuickSort(arry, left, j - 1); // sort out left part
		QuickSort(arry, j + 1, right); // sort out right part


	}
}

void main(void) {

	int a[] = { 2, 12,24,24,154,25,5,67,33,6,72,36,39,21,62,345,62};
	int size = 17;
	QuickSort(a, 0, size-1);
	while (size) {
		printf("%d\n", a[size - 1]);
		size--;
	}


}