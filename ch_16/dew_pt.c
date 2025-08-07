#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define num_gases 16
typedef enum { c2h4o, c3h6o, c6h6, c6h5cl, c4h8o, c2h6o, c8h10, c5h12, ch4o, c4h8oi, c7h16, c6h14, c5h12i, c8h8, c7h8, h2o } gas_code;
typedef struct {gas_code gc; double t_lo, t_hi; double A, B,C;} gas_constants;
typedef struct {gas_code gc; double mf;} fracs_t;
typedef char* string;
typedef enum { false, true} boolean;
const string gas_names[16] = {"Acetaldehyde", "Acetone", "Benzene", "Chlorobenzene", "Ethyl acetate", "Ethyl alcohol", "Ethylbenzene", "Isopentane", "Methyl alcohol", "Methyl ethyl ketone", "n-Heptane", "n-Hexane", "n-Pentane", "Styrene", "Toulene", "Water"};
const gas_constants data[18] = {
    {c2h4o, 45, 70, 6.81089,  992.0,     230.0},
    {c3h6o, -500, 500, 7.02447, 1161.0,     224.0},
    {c6h6, -500, 500, 6.90565, 1211.033,   220.790},
    {c6h5cl, 0, 42, 7.10690, 1500.0,     224.0},
    {c6h5cl, 42, 230, 6.94504, 1413.12,    216.0},
    {c4h8o, 20, 150, 7.09808, 1238.71,    217.0},
    {c2h6o, -500, 500, 8.04494, 1554.3,     222.65},
    {c8h10, -500, 500, 6.95719, 1424.255,   213.206},
    {c5h12, -500, 500, 6.78967, 1020.012,   233.097},
    {ch4o, 20, 140, 7.87863, 1473.11,    230.0},
    {c4h8oi, -500, 500, 6.97421, 1209.6,     216.0},
    {c7h16, -500,500, 6.90240, 1268.115,   216.900},
    {c6h14,  -500,500, 6.87776, 1171.530,   224.366},
    {c5h12i,  -500,500, 6.85221, 1064.63,    232.000},
    {c8h8,  -500,500, 6.92409, 1420.0,     206.0},
    {c7h8,  -500,500, 6.95334, 1343.943,   219.377},
    {h2o, 0, 60, 8.10765, 1750.286,   235.0},
    {h2o, 60,150, 7.96681, 1668.21,    228.0}

};
int mixture(fracs_t gases[MAX]);
void v_pressure(double temp, fracs_t gases[], int n, double p_vap[], double* p_tot); 
void display_menu(boolean bool_ar[num_gases]);
void take_gas_codes(gas_code gc_arr[], int);
void take_mole_fracs(fracs_t gases[MAX], gas_code gc_arr[], int);
int find_constants(gas_code gc, double temp);
void main(){
	fracs_t ar[] = {{c2h4o, 0.0}, {c3h6o, 0.0}, {c6h6, 0.0}, {c6h5cl, 0.0}, {c4h8o, 0.0}, {c2h6o, 0.0}, {c8h10, 0.0}, {c5h12, 0.0}, {ch4o, 0.0}, {c4h8oi, 0.0}, {c7h16, 0.0}, {c6h14, 0.0}, {c5h12i, 0.0}, {c8h8, 0.0}, {c7h8, 0.0}, {h2o, 0.0}};
	gas_code g = c5h12;
	printf("Array entry with c5h12 is %s", gas_names[g]); 
	fracs_t gases[MAX];
	int n = mixture(gases);
	double p_vap_tot;
	double temp;
	printf("What is the temperature?");
	scanf("%lg", &temp);
	double p_vap[n];
	v_pressure(temp, gases, n, p_vap, &p_vap_tot);
	printf("Here is p_vap_tot: %lg", p_vap_tot);
}

void v_pressure(double temp, fracs_t gases[], int n, double p_vap[], double* p_tot){
	//loop through the array until you find the first matching gas code, if temperature is not in the range see if there's a second matching gas code. If there isn't a second matching gas code, indicate with printf statement and set the p_vap to 0 for that gas
     	int j;
	double temp_tot = 0;
	for(int i=0; i<n; i++){
     		j = find_constants(gases[i].gc, temp);
		printf("Calculating for gas %s with a temp range between %lg and %lg\n", gas_names[gases[i].gc], data[j].t_lo, data[j].t_hi);
     		if(j == -1){
     			printf("Cannot calculate the vapor pressure for the entered gases and the entered temperature");
     			return;
     		}
     		else{
     			p_vap[i] = (data[i].A -data[i].B) / (temp + data[i].C);
			temp_tot += p_vap[i];
     		}
	}
	*p_tot = temp_tot;
}
int find_constants(gas_code gc, double temp){
	for(int i =0; i< 18; i++){
     		if(data[i].gc == gc && (temp <= data[i].t_hi && temp >= data[i].t_lo)) return i;
     	}
	return -1;
	}
int mixture(fracs_t gases[MAX]){
	int n;

	printf("How many gases would you like to enter? Put a number between 1 and 10: ");
	do{	
		scanf("%i", &n);
		if(n> 10 || n<1) printf("That number is not between 1 and 10\n");
	}while(!(n <=10 && n>=1));

	gas_code gc_arr[n];
	take_gas_codes(gc_arr,n);
	take_mole_fracs(gases, gc_arr, n);
	for(int i=0; i<n; i++){
		printf("Here's the gas name %s and its associated mole fraction %lg\n", gas_names[gases[i].gc], gases[i].mf);
	}
	
	return n;
}

void take_mole_fracs(fracs_t gases[MAX], gas_code gc_arr[], int n){
	double total_mf = 0;
     	double ind_mf;
	for(int i=0; i<n-1; i++){
     		printf("Please enter the mole fraction for %s", gas_names[gc_arr[i]]);
     		scanf("%lg", &ind_mf);
     		while((ind_mf + total_mf) >= 1){
     			printf("The total mole fractions cannot exceed 1. Please enter a value less than %lg for the mole fraction of %s", (1.0-total_mf), gas_names[gc_arr[i]]);
     			scanf("%lg", &ind_mf);
     		}
     		total_mf += ind_mf;
     		gases[i].gc = gc_arr[i]; gases[i].mf= ind_mf;
     	}
	gases[n-1].gc = gc_arr[n-1]; gases[n-1].mf= 1.0-total_mf;
}
void take_gas_codes(gas_code gc_arr[], int n){
	boolean remaining_indices[num_gases] = {false};  
	int valid_choices = 0;
	while(valid_choices < n){
		int choice; 
		display_menu(remaining_indices);
		scanf("%i", &choice);
		while(choice >= num_gases || remaining_indices[choice] == true){
			printf("Select a valid choice\n");
			scanf("%i", &choice);
		}
		gc_arr[valid_choices] = choice;	
		remaining_indices[choice] = true;
		++valid_choices;
	}	
}

void display_menu(boolean bool_ar[num_gases]){
	for(int i = 0; i<num_gases; i++){
     		if(bool_ar[i] == true) continue;
		else{
     			printf("Type %i to select %s\n", i, gas_names[i]);
		}
	}
}
