#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX 1000
char* take_input(int* count);
void upper_word();
void print_str(char* str, int len);


void main(){
	upper_word();
}

char* take_input(int* ptr){
	int count = 0;
	char* buffer = (char*) malloc(MAX);
	
	while(count <MAX){
		buffer[count] = getchar();
		if(buffer[count] == '\n') break;
		count++;
	}

	*ptr = count;
	if(count == 0) return buffer;
	buffer = (char*) realloc(buffer, count);
	return buffer;
}

void print_str(char* str, int len){
	char* start = str;
	char* end = str + len;
	for(start; start< end; start++){
     		printf("%c", *start);
	}
	puts("\n");
}
		
void upper_word(){
	int count = 1;
	srand(time(NULL));
	char* str = NULL;
	char* start_p;
	char* end_p;
	while(1){
		str = take_input(&count);
		if(count == 0) break;
		int start = rand() % count;

		print_str(str, count);
		start_p = str + start;
		end_p = str + count;
		for(start_p; start_p < end_p; start_p++){
			*start_p = toupper(*start_p);
		}
		print_str(str, count);
	}
}

