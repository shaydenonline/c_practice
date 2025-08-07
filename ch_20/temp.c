#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {double x,y;} point_t;
void main(){
	int* ptr_1;
	int val = 2;
	float mat[2][2];
	float* begin = &mat[0][0];
	printf("Are these equal or not? &mat and &mat[0][0] %i\n", &mat == &mat[0][0]);
	mat[0][0] = 2;
	printf("Dereferenced begin: %g should be 2\n", *begin);

	float* end = begin + 3;
	mat[1][1] = 4;
	printf("Derenced end: %g should be 4\n", *end);
	point_t pt = {1,4};
	point_t* ptr = &pt;
	printf("I referenced x: %g\n", ptr->x);
/*
	printf("Here's the original address and value of ptr_1: %p, %i\n", ptr_1, *ptr_1);
	ptr_1 = &val;
	printf("Here's the new address and value of ptr_1: %p, %i\n", ptr_1, *ptr_1);
*/
}
