/*
 * EX2.c
 *
 *  Created on: Apr 18, 2023
 *      Author: ARAFA
 */


#include<stdio.h>
#define SIZE 10
int main(){
	float arr[SIZE];
	int x,i;
	double sum=0;
	printf("Please enter the number of elements\n");
	fflush(stdout);
	scanf("%d",&x);		// take num of elements from user

	for (i=0 ; i<x ; i++){		// loop to get the numbers
		printf("Enter number :");
		fflush(stdout);
		scanf("%f",&arr[i]);
		sum += arr[i];

	}

	printf("\nAverage %f",sum/x);		// printing the average
	return 0;
}
