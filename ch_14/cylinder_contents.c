#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 20

typedef enum {false, true} bool;
typedef char string[10];
typedef struct {double diameter, height, mass, volume, density;} cyl_type;
const string arr[2] = {"Floats", "Sinks"};

void read_barrel(cyl_type*);
bool floats(cyl_type*);

void main(){
	cyl_type barrels[MAX];
	int count;
	printf("You can enter up to %d barrels. How many barrels are you entering? ", MAX);
	scanf("%d", &count);
	if(count > MAX)	printf("You entered a number greater than %d. So I'm just going to read %d\n", MAX, MAX);

	int incr = 0;
	while(incr < count){
		read_barrel(&barrels[incr]);
		++incr;
	}
	
	int i = 0;
	double total_mass = 0;
	double total_vol = 0;
	while(i < count){
		printf("|%5.3g|%5.3g|%5.3g|%5.3g|%5.3g|%s\n", barrels[i].diameter, barrels[i].height, 
				barrels[i].mass, barrels[i].volume, barrels[i].density, arr[floats(&barrels[i])]);
		++i;
		total_mass += barrels[i].mass;
		total_vol += barrels[i].volume;
	}
	printf("Total mass: %g Total volume: %g\n", total_mass, total_vol);
}
bool floats(cyl_type* cyl){
	if(cyl->density < 1) return true;
	else return false;
}
void read_barrel(cyl_type* cyl){
	printf("Enter the diameter of a cylinder in cm: ");
	scanf("%lg", &cyl->diameter);
	printf("Enter the height of a cylinder in cm: ");
	scanf("%lg", &cyl->height);
	printf("Enter the mass of a cylinder in g: ");
	scanf("%lg", &cyl->mass);
	
	cyl_type im_lazy = *cyl;
	double volume = M_PI * pow(im_lazy.diameter/2.0, 2.0) * im_lazy.height;
	double rho = im_lazy.mass / volume;
	cyl->volume = volume;
	cyl->density = rho;
}
