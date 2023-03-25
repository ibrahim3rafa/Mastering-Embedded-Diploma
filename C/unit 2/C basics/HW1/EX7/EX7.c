/*
 * EX7.c
 *
 *  Created on: Mar 25, 2023
 *      Author: ARAFA
 */

#include<stdio.h>
void swap_without_temp(float a , float b ){

	a = a+b;
	b = a-b;
	a = a-b;

	printf("the value of a after swapping is %.2f ",a);
	printf("The value of b after swapping is %.2f ",b);
}
int main(){
	float a,b;
	fflush(stdout);
	printf("Enter value of a : ");
	fflush(stdout);
	scanf(" %f",&a);
	fflush(stdout);
	printf("\nEnter value of b : \n");
	fflush(stdout);
	scanf(" %f",&b);
	swap_without_temp(a,b);
}
