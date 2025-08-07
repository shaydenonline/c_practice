#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef FILE* stream;
#define mask 0x20
void toggle_bits(stream, stream);
void all_upper(stream, stream);
void all_lower(stream, stream);

void main(){
	stream fin = fopen("text.in", "r");
	stream fout = fopen("text.out", "w");
	toggle_bits(fin, fout);
	all_upper(fin, fout);
	all_lower(fin, fout);
}
void toggle_bits(stream fin, stream fout){
	
	unsigned int ch = 'a';
	while(ch != (unsigned int) '\n'){
		ch = (unsigned int) fgetc(fin);
		if(isalpha(ch))	ch ^= mask;
		fputc(ch, fout);
		if(feof(fin)) break;

	}
}

void all_upper(stream fin, stream fout){

	unsigned int ch = 'a';
	while(ch != (unsigned int) '\n'){
		ch = (unsigned int) fgetc(fin);
		if(isalpha(ch))	ch &= ~mask;
		fputc(ch, fout);
		if(feof(fin)) break;

	}
}

void all_lower(stream fin, stream fout){
	unsigned int ch = 'a';
	while(ch != (unsigned int) '\n'){
		ch = (unsigned int) fgetc(fin);
		if(isalpha(ch))	ch |= mask;
		fputc(ch, fout);
		if(feof(fin)) break;

	}
}

