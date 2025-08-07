#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pt {unsigned horiz, vert;} point;
typedef struct ln {point pt_1, pt_2; unsigned thick;} line;

const line corners = { {0,0}, {1599, 1199}, 15};

line* get_line(line, line*);

void main(){
	srand(time(NULL));
	printf("These are the problems you're doing %d and %d\n", rand() % 11, rand() % 11);
}


line* get_line(line corners, line* ln_ptr){
	
	printf("User please enter the horizontal and vertical components of point1");
	scanf("%u", &ln_ptr->pt_1.horiz);
	if(ln_ptr->pt_1.horiz > corners.pt_2.horiz || ln_ptr->pt_1.horiz < corners.pt_1.horiz){
		printf("That's not a valif input for horizontal point, we're just going to set it as 1599.\n");
		ln_ptr->pt_1.horiz = corners.pt_2.horiz;
	}
	scanf("%u", &ln_ptr->pt_1.vert);
	printf("Now the horizontal and vertical components of point 2\n");
	scanf("%u", &ln_ptr->pt_2.horiz);
	scanf("%u", &ln_ptr->pt_2.vert);
	printf("Now the thickness\n");
	scanf("%u", &ln_ptr->thick);
	return ln_ptr;
	
}
