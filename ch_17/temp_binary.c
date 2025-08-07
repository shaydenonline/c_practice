#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define width 1000
#define len 688

typedef FILE* stream;
typedef unsigned char pixel;
typedef pixel picture[width][len];


void main(){
	stream bin, bout;
	bin = fopen("out.png", "rb");
	if(bin == NULL) printf("For some reason didn't establish a pointer\n");
	bout = fopen("my_output_img.png", "wb");
	picture image;
	int n = fread(image, sizeof(pixel), len*width, bin);
	printf("Here we have read the binary file");
	int closed = fclose(bin);
	if(closed==0) printf("bin successfully closed and freed");
	printf("Here's the sizeof the image: %li", sizeof(image));	
	printf("Here's a pixel from the image. What's it's value? %i, and another %i %i", image[0][0], image[100][100], image[200][200]);
	/*
	for(int i=0; i<width; i++){
		for(int j=0; j<width; j++){
     			image[i][j] ^= 0xFF;
		}
	}
	*/
	n = fwrite(image, sizeof(pixel), len*width, bout);

	

}
