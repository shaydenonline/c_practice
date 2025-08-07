#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef FILE* stream;
void main(){
	stream fin, males, females, errors;

	fin= fopen("people.in", "r");
	males = fopen("male.out", "w");
	females = fopen("female.out", "w");
	errors = fopen("error.log", "w");
	char name[24];
	int age;
	char gend;
	while(1){
		int n = fscanf(fin, "%23[^,], %i %c", name, &age, &gend);
		if (feof(fin)) break;

		if(n != 3) fprintf(errors, "An error occured:");
		if(age >= 5 && age <= 18){
			if(gend == 'F') fprintf(females, "%s , %i %c", name, age, gend);
			if(gend == 'M') fprintf(males, "%s, %i %c", name, age, gend);
		}
	}
}
