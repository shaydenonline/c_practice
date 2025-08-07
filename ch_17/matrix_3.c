#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This library for matrix operations contains a function read_mat that will
 * create an array from a file with doubles separated by spaces and each row on a new line 
 * refer to my_mat.in (should be in same directory) for example.
 * Also contains a function to transpose and print a matrix. print_horiz is just for printing out lines
 * And init_mat is for initializing a matrix from within this program of dimensions size*size all with integers
*/

#define SIZE 3
#define M 2
#define N 3
#define P 2

typedef double matrix[SIZE][SIZE];
typedef FILE* stream;
typedef char* string;

void transpose(matrix mat);
void print_mat(matrix mat);
void init_mat(matrix mat);
void print_horiz();
void read_mat(matrix mat, string filename);
void multiply(double mat1[M][N], double mat2[N][P], double result_mat[M][P]);

void main(){
	double mat1[M][N] = { {1,2,3}, {4, 5, 6}};
	double mat2[N][P] = { {4,7}, {5, 8}, {6, 9}};
	double res_mat[M][P];
	multiply(mat1, mat2, res_mat);
	for(int i=0; i<M; i++){
		for(int j=0; j<P; j++){
     			printf(" %4g", res_mat[i][j]);
		}
		putchar('\n');
	}
	matrix mat;
	string name = "my_mat.in";
	read_mat(mat, name);
	print_mat(mat);
}

void multiply(double mat1[M][N], double mat2[N][P], double result_mat[M][P]){
	int i,j,k;
     	for(k=0; k<M; k++){
		for(j=0; j<P; j++){
			result_mat[k][j] = 0;
     			for(i=0; i<N; i++){
	  			result_mat[k][j] += (mat1[k][i]* mat2[i][j]);
	  		}
	  	}
	}
}
     				

     
void read_mat(matrix mat, string filename){
	stream fin;
	fin = fopen(filename, "r");
	int row, col;
	for(row=0; row<SIZE; row++){
     		for(col=0; col<SIZE; col++){
     			fscanf(fin, " %lg", &mat[row][col]);
     		}
     		if(fgetc(fin) != (int)'\n') printf("Something strange might be happening");
	}
}
//initializes a matrix of integers from 1 - (SIZE)(SIZE) in row major order
void init_mat(matrix mat){
	int row, col;
	int i = 1;
	for(row=0; row<SIZE; row++){
     		for(col=0; col<SIZE; col++){
			mat[row][col] = i;
			++i;
		}
	}
}
//gets the transpose of a matrix
void transpose(matrix mat){
     	double temp;
	int fun_size = SIZE - 1;
	for(int i=0; i<= fun_size; i++){
		for(int j=fun_size; j>i; j--){
     			temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}
}
void print_mat(matrix mat){
	int row, col;
	print_horiz();
	for(row=0; row<SIZE; row++){
     		for(col=0; col<SIZE; col++){
     			printf("| %4g", mat[row][col]);
		}
		putchar('|');
		putchar('\n');

	}
}

void print_horiz(){
	for(int i = 0; i< SIZE*5; i++){
		putchar('_');
	}
	putchar('\n');
}
