/*
 * EX1.c
 *
 *  Created on: Apr 18, 2023
 *      Author: ARAFA
 */

#include<stdio.h>

int main(){
	float a[2][2];
	float b[2][2];
	int i,j,k,l;

	for(i=0 ; i<2 ; i++){
		printf("Enter the elements of matrix %d \n",i+1);
		for(j=0 ; j<2 ; j++){	 // inner loop to get elements of first-array
			printf("Enter a%d%d :",i+1,j+1);
			fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}
	for(i=0 ; i<2 ; i++){
		printf("Enter the elements of matrix %d \n",i+1);
		for(j=0 ; j<2 ; j++){	 // inner loop to get elements of second-array
			printf("Enter b%d%d :",i+1,j+1);
			fflush(stdout);
			scanf("%f",&b[i][j]);
		}
	}
	double c[i][j];		// array to store sum
	for(i=0 ; i<2 ; i++){ 	// loop to store sum in c
		for(j=0 ; j<2 ; j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	printf("Sum of Matrix\n");
	for(k=0 ;k<2 ; k++){	// printing the sum
		for(l=0 ; l<2 ; l++){
			printf("%f\t",(c[k][l]));
		}
		printf("\n");
	}

	return 0;
}
