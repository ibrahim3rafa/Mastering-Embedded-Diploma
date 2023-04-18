/*
 * EX3.c
 *
 *  Created on: Apr 18, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

#define SIZE 10

int main(){
	int a[SIZE][SIZE];
	int trans[SIZE][SIZE];
	int x,y;
	int i,j;
	printf("Please enter rows and coloumns of matrix\n");
	fflush(stdout);
	scanf("%d %d",&x,&y);

	printf("Enter elements of matrix:\n");
	for (i=0 ; i<x ; i++){			// get elements of array
		for(j=0 ; j<y ; j++){
			printf("Enter element a%d%d:",i,j);
			fflush(stdout);
			scanf("%d",&a[i][j]);
		}
	}

	printf("Entered matrix is \n");
	for(i=0 ; i<x ; i++){				// loop to print entered matrix
		for(j=0 ; j<y ; j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

	// loop to transpose matrix
	for (i=0 ; i<x ; i++){
		for(j=0 ; j<y ; j++){
			trans[j][i] = a[i][j];
		}
	}

	printf("Transpose of matrix is \n");

	for(i=0 ; i<y ; i++){
		for(j=0 ; j<x ; j++){
			printf("%d\t",trans[i][j]);
		}
		printf("\n");
	}




	return 0;
}
