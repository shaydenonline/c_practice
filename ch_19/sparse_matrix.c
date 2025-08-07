#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {int row, col; double value;} triple;
triple* get_mat(int* max_len);
void show_mat(triple ar[], int len);
void main(){
	
	int* int_ptr;
	triple* ar = get_mat(int_ptr);
	show_mat(ar, *int_ptr);
}

void show_mat(triple ar[], int len){
     	printf("Row   Col   Value\n");
	for(int i=0; i<len; i++){
     		printf("%-6i%-6i%g\n",ar[i].row, ar[i].col, ar[i].value);
	}
}

triple* get_mat(int* max_len){
	int row, col, i=0;
	double value=0;
	triple* ar = (triple*) malloc(sizeof(triple)*10);
	*max_len = 10;
	printf("Assuming you have a sparse matrix what and where are the entries?\n");
	printf("Enter in the form of: row,col,value\n");
	printf("When you are finished enter a negative value for the row.\n");

	do{	
		scanf("%i,%i,%lg",&row, &col, &value);
		if(row < 0 || col < 0) break;
		ar[i].row=row; ar[i].col=col; ar[i].value=value;
		++i;
		if(i == *max_len){
			ar = realloc(ar, i * 2 * sizeof(triple));
			*max_len *= 2;
		}
	}while(1);
	ar = realloc(ar, i* sizeof(triple));
	*max_len = i;
	return ar;

}
