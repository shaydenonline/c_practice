#include <stdio.h>
#include <math.h>
#include "rect.h"

boolean compare_points(float, float);
void switch_pts(float* pt_1, float* pt_2);
rect_t check_edge_cases(rect_t rect);
void print_rect_info(rect_t rect);
rect_t handle_input();
void line_in(rect_t rect, point_t pt);
void pt_in(rect_t rect, point_t pt);
boolean in_or_out(rect_t rect, point_t pt);
void rect_in(rect_t rect, point_t pt);
point_t compare_position(rect_t rect);
boolean compare_lo_point(rect_t rect, point_t pt);
void take_rect_and_pt(void);

void take_rect_and_pt(){
	rect_t rect = handle_input();
	point_t pt;
	while(1){
		pt = compare_position(rect);
		if(compare_lo_point(rect, pt)) break;
	}
	printf("You have no rectangle anymore. The program is ending.");
}



boolean compare_points(float pt_1, float pt_2){
	if(fabs(pt_1 - pt_2) < .000001) return true;
	else return false;
}

void switch_pts(float* pt_1, float* pt_2){
	float p = *pt_1;
	*pt_1 = *pt_2;
	*pt_2 = p;
}
rect_t check_edge_cases(rect_t rect){
	if(compare_points(rect.lo.x, rect.hi.x) && compare_points(rect.lo.y, rect.hi.y)){
		rect.shape = point;
		printf("You have created a point\n");
		return rect;
	}
	else if(compare_points(rect.lo.x, rect.hi.x) || compare_points(rect.lo.y, rect.hi.y)){
		rect.shape = line;
		printf("You have created a line\n");
		return rect;
	}
	else if(rect.lo.x > rect.hi.x){
		printf("The left x value is supposed to be less than the right x value. The input has been corrected.\n");
		switch_pts(&rect.lo.x, &rect.hi.x);
	}
	else if(rect.lo.y > rect.hi.y){
		printf("The bottom y value is supposed to be less than the top y value. The input has been corrected.\n");
		switch_pts(&rect.lo.y, &rect.hi.y);
	}
	rect.shape = rectangle;
	return rect;
}

void print_rect_info(rect_t rect){
	printf("rect.lo.x: %.7g rect.hi.x: %.7g rect.lo.y %.7g rect.hi.y %.7g rect.shape %d\n", rect.lo.x, rect.hi.x, rect.lo.y, rect.hi.y, rect.shape);
}
rect_t handle_input(){
	rect_t rect;
	rect.shape = 0;
	printf("Please enter the bottom left corner of this rectangle\n");
	scanf("%f%f", &rect.lo.x, &rect.lo.y);
	printf("Please enter the top right corner of this rectangle\n");
	scanf("%f%f", &rect.hi.x, &rect.hi.y);
	rect_t correct_rect = check_edge_cases(rect);
	
	return correct_rect;
}

void pt_in(rect_t rect, point_t pt){
	if(compare_points(rect.lo.x, pt.x) && compare_points(rect.lo.y, pt.y)) printf("on a corner\n");
	else printf("outside\n");
}

void line_in(rect_t rect, point_t pt){
	if((compare_points(rect.lo.x, pt.x) || compare_points(rect.hi.x, pt.x)) && 
	(compare_points(rect.lo.y, pt.y) || compare_points(rect.hi.y, pt.y))) printf("on a corner\n");

	else if(compare_points(rect.lo.x, pt.x)) printf("on a line\n");
	else if(compare_points(rect.lo.y, pt.y)) printf("on a line\n");
	else if(compare_points(rect.hi.x, pt.x)) printf("on a line\n");
	else if(compare_points(rect.hi.y, pt.y)) printf("on a line\n");
	else printf("outside\n");
}

boolean in_or_out(rect_t rect, point_t pt){
	int check_lo = (rect.lo.x < pt.x) && (rect.lo.y < pt.y);
	int check_hi = (rect.hi.x > pt.x) && (rect.hi.y > pt.y);
	return check_lo && check_hi;
}

void rect_in(rect_t rect, point_t pt){
	if(in_or_out(rect, pt)) printf("inside\n");
	else line_in(rect, pt);
}
boolean compare_lo_point(rect_t rect, point_t pt){
	if(compare_points(rect.lo.x, pt.x) && compare_points(rect.lo.y, pt.y)) return true;
	else return false;
}
point_t compare_position(rect_t rect){
	printf("Enter a point:\n");
	point_t pt;
	scanf("%g%g", &pt.x, &pt.y);
	
	switch(rect.shape){
		case point: pt_in(rect, pt); return pt;
		case line: line_in(rect, pt); return pt;
		default: rect_in(rect, pt); return pt;
	}
}
