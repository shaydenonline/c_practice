#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float* row;
typedef float* col;
typedef row* mat;

mat* init_mat();
void main(){
	init_mat();
	
}

mat* init_mat(){
	FILE* fin = fopen("matrix.in", "r");
	if(fin == NULL){
		printf("Couldn't successfully open stream\n");
		exit(1);
	}
	int i, j;
	int read = fscanf(fin, "%i %i", &i, &j);
	if(read != 2){
		printf("For some reason only %i integers were read", read);
		exit(1);
	}
	
	mat* matrix = malloc(i * j * sizeof(float*));

	printf("Here's i and j: %i %i", i, j);
	row* row_avg = malloc(i * sizeof(float));
	col* col_avg = malloc(j * sizeof(float));

	return matrix;
}

