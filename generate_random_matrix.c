#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pt {unsigned horiz, vert;} point;
typedef struct ln {point pt_1, pt_2; unsigned thick;} line;



void get_matrix_dimensions(int *row, int *col);

void main(){
	srand(time(NULL));
	int row, col; 
	get_matrix_dimensions(&row, &col);
	int matrix[row][col];
	for(int r=0; r<row; r++){
		for(int c=0; c<col; c++){
     			matrix[r][c] = rand() % 11;
     			printf("%d ", matrix[r][c]);
		}
		printf("\n");
	}
}

void get_matrix_dimensions(int *row, int *col){
	printf("Please enter the rows of your matrix: ");
	scanf("%d", row);
	printf("Please enter the cols of your matrix: ");
	scanf("%d", col);
}


