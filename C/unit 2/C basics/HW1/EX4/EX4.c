/*
 * EX4.c
 *
 *  Created on: Mar 15, 2023
 *      Author: ARAFA
 */

#include<stdio.h>

int main(){

	float num1,num2;
	double product = 0;

	printf("Entering two floating numbers\n");
	printf("Enter the first num\n");
	fflush(stdout);
	scanf("%f",&num1);
	printf("Enter the second num\n");
	fflush(stdout);
	scanf("%f",&num2);

	product = num1*num2;
	printf("Product : %f ",product);
}
