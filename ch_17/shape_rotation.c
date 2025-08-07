#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef FILE* stream;
typedef double point[2];
#define MAX 10

void translate_shape(double, point, point ar[]);
void main(){
	stream fin = fopen("shape.in", "r");
	point shape[MAX];
	for(int i=0; i<MAX; i++){
		int n = fscanf(fin, "%lg %lg", &shape[i][0], &shape[i][1]);
		if(n != 2) printf("Something has gone wrong, only %i was read", n);
	}
	printf("What should theta be? (Enter a double between 0 and 6.28)");
	double rad;
	int x,y;
	scanf("%lg", &rad);
	printf("What should x and y translation constants be? Taking integer input");
	scanf("%i%i", &x, &y);
	point ar = {x,y};
	translate_shape(rad, ar, shape);
}
void translate_shape(double theta, point T, point ar[MAX]){
	double new_x, new_y;
	for(int i=0; i<MAX; i++){
     		new_x = ar[i][0] * cos(theta) - ar[i][1]* sin(theta) + T[0]; 
		new_y = ar[i][0] * sin(theta) - ar[i][1]* cos(theta) + T[1]; 
     		printf("Original point: (%5.2lg %5.2lg)", ar[i][0], ar[i][1]);
		ar[i][0] = new_x; ar[i][1] = new_y;
		printf("\t -> (%5.2lg, %5.2lg)\n", ar[i][0], ar[i][1]);
	}
}
