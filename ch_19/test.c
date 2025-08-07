#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
void swap(string ar[], int i, int j);
void recycle_mem(string ptrs[], int num_strings);
void main(){
	int* equation;
	int* equal;
	int* nequal;
	equal = equation;
	string ar[2] = {"A capital a", "z capital z"};
	swap(ar, 1,0);
	int i =0;
}

void swap(string ar[], int i, int j){
	printf("pointer for ar[j]: %s pointer for ar[i]: %s\n", ar[j], ar[i]); 
	printf("Result of strcmp: %i", strcmp(ar[i], ar[j]));
	if(strcmp(ar[i], ar[j])>0){
		printf("If block executes\n");
		string temp = ar[i];	
		ar[i] = ar[j];
		ar[j] = temp;
	}
	printf("pointer for ar[j]: %s pointer for ar[i]: %s\n", ar[j], ar[i]); 
}

void recycle_mem(string ptrs[], int num_strings){
	for(int i=0; i<num_strings; i++){
		free(ptrs[i]);
	}
	free(ptrs);
}
