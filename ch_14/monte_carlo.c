#include <stdio.h>
#include "rect.h"

int main(void){
	rect_t rec = handle_input();
	printf("Here is the corner: (%f, %f) and another corner (%f, %f)", rec.lo.x, rec.lo.y, rec.hi.x, rec.hi.y); 
	return 0;
}
