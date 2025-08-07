#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double abs_temp_metric(double);
double abs_temp_english(double);
int display_error(double, char, double, double);
double calc_final_pressure(double, double, double);
typedef FILE* stream;
		
void main(){
	stream fin, fout;
	fin = fopen("pressure.in", "r");
	fout = fopen("press.out", "w");
	char code;
	double p1, t1, t2;
	while(1){
		fscanf(fin, "%lg %c %lg %lg", &p1, &code, &t1, &t2);
		if (feof(fin)) break;
		if(display_error(p1, code, t1, t2)) fflush(fin);
		else{
			double t1_conv, t2_conv;
			t1_conv = code == 'F'? abs_temp_english(t1) : abs_temp_metric(t1);
			t2_conv = code == 'F'? abs_temp_english(t2): abs_temp_metric(t2);
	
			double p2 = calc_final_pressure(p1, t2_conv, t1_conv);
			fprintf(fout, "%lg %lg %lg %lg\n", p1, t1_conv, t2_conv, p2);
		}
	}
}
int display_error(double p1, char code, double t1, double t2){
	if(p1 <= 0){
		printf("p1: %lg shouldn't be negative", p1);
		return 1;
	}
	if((t1 <= -459.67 || t2 <= -459.67) && code == 'F'){
		printf("A farenheight temperature either t1: %lg or t2: %lg is below absolute 0", t1, t2);
		return 1;
	}
	if((t1 <= -273.15 || t2 <= -273.15) && code == 'C'){
		printf("A celsius temperature either t1: %lg or t2: %lg is below absolute 0", t1, t2);
		return 1;
	}
	return 0;
}
double calc_final_pressure(double p1, double t2, double t1){
	return p1* (t2 / t1);
}
double abs_temp_metric(double cels){
	return cels + 273.0;
}
double abs_temp_english(double far){
	return far + 460.0;
}
