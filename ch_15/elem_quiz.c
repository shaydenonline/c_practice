#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
typedef char* string;
typedef FILE* stream;
typedef struct {short int atomic_number; string symbol; string name;} question_t;
question_t ar[MAX];
void main(){
	char ph[3];
	stream quest_stream = fopen("elements_list.txt", "rt");
	strcpy(ph, "Au");
	for(int i =0; i<MAX; i++){
		string str;
		int j = fscanf(quest_stream, "%s", str);
		if (j==1) printf("success"); 
		else fflush(quest_stream); 
		printf("%s here's a string", str);
	}

	printf("%s here's ph", ph);

	question_t q = {1, "Au", "Gold"};
	ar[0] = q;
	printf("Here's my structure %hi %s %s", ar[0].atomic_number, ar[0].symbol, ar[0].name);
	printf("Here's my structure %hi %s %s", ar[3].atomic_number, ar[3].symbol, ar[3].name);
}
