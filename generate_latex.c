#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int rows, cols;
	printf("How many rows would you like the generic matrix to have?\n");
	scanf("%d", &rows);
	printf("How many columns would you like the generic matrix to have?\n");
	scanf("%d", &cols);
     	
     	printf("\n\\begin{matrix}\n");
	
	for(int row =1; row<=rows; row++){
		for(int col=1; col<cols; col++){
     		printf("a_{%d%d} & ", row, col);
		}
		if(row < rows) printf("a_{%d%d}\\\\\n", row, cols);
		else printf("a_{%d%d}\n", row, cols);
	}
	printf("\\end{matrix}\n");
}

