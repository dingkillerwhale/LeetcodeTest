#include <stdio.h>
#include <stdbool.h>


bool checkPossibility(int* nums, int numsSize) {
	int flag = 0;
	if (*nums > *(nums + 1)) flag++; // compare first two elements
	nums++; // move one element
	for (; (numsSize - 2 > 0) && (flag < 2); numsSize--, nums++)
		if (*nums> *(nums + 1)) {
			flag++;
			if (*(nums - 1) > *(nums + 1)) *(nums + 1) = *nums; // change the smaller element
			else *nums = *(nums + 1); // change the bigger element
		}
	if (flag == 2) return false;
	return true;
}

void main(void) {
	int a[] = {4,3,3};
	int size = 3;
	printf(checkPossibility(a, size) ?"true":"false");
}
