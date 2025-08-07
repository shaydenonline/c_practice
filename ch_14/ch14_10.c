#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {AM, PM, d} APD;
typedef struct {unsigned short days, hours, minutes, seconds; APD apd;} time_unit;
typedef char input_s[3];

time_unit input_time();
void main(){
	time_unit main_t;
	main_t = input_time();
	printf("Here is main_t days %u hours %u minutes %u seconds %u", main_t.days, main_t.hours, main_t.minutes, main_t.seconds);
}
time_unit input_time(){
	time_unit t_u;
	t_u.hours = 25;
	t_u.minutes = 61;
	t_u.seconds = 61;
	printf("Please enter the number of days: ");
	scanf("%hu", &t_u.days);

	printf("Is it am or pm?");
	input_s input;
	scanf("%s", input);

	int am_cmp = strcmp((input), "am");
	int pm_cmp = strcmp((input), "pm");
	while(am_cmp != 0 && pm_cmp != 0){
		printf("Try entering again in the format 'am' or 'pm'");
		scanf("%s",input);
		am_cmp = strcmp((input), "am");
		pm_cmp = strcmp((input), "pm");

	}
	if(am_cmp == 0) t_u.apd = AM;
	else t_u.apd = PM;
	while(t_u.hours >= 24){
		printf("Please enter the number of hours (should be less than 24)");
		scanf("%hu", &t_u.hours);
	}
	while(t_u.minutes >= 60){
		printf("Please enter the number of minutes (should be less than 60)");
		scanf("%hu", &t_u.minutes);
	}
	while(t_u.seconds >= 60){
		printf("Please enter the number of seconds (should be less than 60)");
		scanf("%hu", &t_u.seconds);
	}
	if(t_u.hours < 12 && t_u.apd == PM) t_u.hours += 12;
	return t_u;
}
