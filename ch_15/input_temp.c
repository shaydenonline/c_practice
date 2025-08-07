#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef FILE* stream;
void main(){
	stream f_in, f_out;
	char* my_str = "here's some text it's a pointer";
	f_in = fopen("testprog.in", "r");
	char code, name[24], title[24], company[32], label[32];
	char ch;
	fscanf(f_in, "%24[^,], %24[^,], %32[^.].", name, title, label);
	printf("here is name: %s here is title %s here is label %s", name, title, label);


	if(feof(f_in)) printf("feof reached");
	f_out = fopen("testprog.out", "w");
	if(f_out != NULL){
		fputs(my_str, f_out);
	}
}
