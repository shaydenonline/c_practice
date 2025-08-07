#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef FILE* stream;
typedef unsigned char unsigned_chunk[4];
void handle_bits(stream, unsigned_chunk);
//Quite possibly the coolest thing I've made in the process of learning c. You can see what your binary executable file looks like in uuencode language!


void main(void){
	char f_name[256];
	printf("Please enter a valid file name: ");
	scanf("%255s", f_name);
	stream fin = fopen("problem_1", "rb");
	if(fin == NULL) printf("Ok can't open fin for some reason.i\n");

	
	unsigned_chunk buffer;
	size_t bits;
	int eof;
	stream fout = fopen("ascii.out", "w");
	
	while(1){
		bits = fread(buffer, sizeof(unsigned char), 3, fin);
		eof = feof(fin);
		while(bits < 3 && bits > 0){
			printf("Seems we've reached the eof and we're appending bit chunks");
			buffer[bits]=0;
			++bits;
		}
		
		handle_bits(fout, buffer);
		if(eof) break;
	}
}
void handle_bits(stream fout, unsigned_chunk buffer){
	unsigned char ascii_ar[4];
	unsigned char mask_1= 0xFC;
	unsigned char mask_2[2] = {0x03, 0xF0};
	unsigned char mask_3[2] = {0x0F, 0xC0};
	unsigned char mask_4 = 0x3F;
	unsigned char hex_32 = 0x20;
	ascii_ar[0] = ((buffer[0] & mask_1)>> 2) + hex_32;
	ascii_ar[1] = (((mask_2[0] & buffer[0]) << 4) | ((mask_2[1] & buffer[1]) >> 4)) + hex_32;
	ascii_ar[2] = (((buffer[1] & mask_3[0])<<2) | ((buffer[2] & mask_3[1])>>6)) + hex_32;
	ascii_ar[3] = (buffer[2] & mask_4) + hex_32;
	int i = fputs(ascii_ar, fout);
	if(i < 0) printf("Writing wasn't successful\n");
}



