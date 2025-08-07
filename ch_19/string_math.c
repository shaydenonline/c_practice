#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Ain't this a cool library? Can add integers of any size via string arithmetic and some dynamic memory allocation.

#define MAX 10
typedef char* string;
typedef short unsigned digit;

string take_integer(int* ptr);
digit* add_digits(string arg1, string arg2, int size1, int size2, int* added_size);

void main(){
	printf("Enter the first argument for addition. Can be as many digits as you want. To stop, enter a new line.\n");
	int size1, size2;
	string ret1, ret2;
	ret1 = take_integer(&size1);
	printf("Enter the second argument for addition. Can be as many digits as you want. To stop, enter a new line.\n");
	ret2 = take_integer(&size2);
	int added_size;
	digit* added=add_digits(ret1, ret2, size1, size2, &added_size);		
	printf("And here's the product");
	for(int i=0; i<added_size;i++){
		printf("%hi", added[i]);
	}
	
}


digit* add_digits(string arg1, string arg2, int size1, int size2, int* added_size){
	int rounds = size1 > size2 ? size2 : size1;
	int g_size = size1 > size2 ? size1 : size2;
	string large_arr = g_size == size1 ? arg1 : arg2;


	digit* added = (digit*) malloc( ++g_size * sizeof(digit));
	int i =0;
	--size1;
	--size2;
	digit carried =  0;
	digit d1, d2, prod;
	while(i < g_size){
		if(i <rounds){
			d1= arg1[size1-i] - '0';
			d2 = arg2[size2-i] - '0';
			prod = d1 + d2 + carried;
			if(prod >= 10){
				carried = 1;
				prod -= 10;
			}
			else carried = 0;
		}
		else if(i < g_size -1){
			d1 = large_arr[g_size-2- i] - '0';
			prod = d1 + carried;
			if(prod >= 10){
				carried = 1;
				prod -= 10;
			}
			else{
				carried = 0;
			}
		}
		else{
			prod = carried;
		}
		added[g_size-1-i] = prod;
		i++;
	}
	*added_size = g_size;
	return added;
}

string take_integer(int* ptr){
	int act_count = 0;
	char c = '0';
	int i = 0;
	int cur_size = MAX;
	string arg1 = (string) malloc(MAX * sizeof(char));
	if(arg1 == NULL){
		printf("Couldn't allocate enough memory. Aborting program.");
		exit(1);
	}
	

	while(c!='\n'){
		if(i >= cur_size){
			arg1 = realloc(arg1, 2 * cur_size * sizeof(char));
			if(arg1 == NULL){
				printf("Couldn't allocate enough memory. Aborting program.");
				exit(1);
			}
			i = cur_size;
			cur_size *=2;
		}
		c = (char) getchar();
		arg1[i] = c;
		++i;
		++act_count;
	}
	*ptr = --act_count;
	arg1 = realloc(arg1, act_count * sizeof(char));
	return arg1;
}

