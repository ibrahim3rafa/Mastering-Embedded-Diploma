/*
 * EX3.c
 *
 *  Created on: Mar 14, 2023
 *      Author: ARAFA
 */

//program to get sum of two integers

#include<stdio.h>

int main(){
	int num1,num2;
	long sum = 0;

	printf("Please enter the two integers\n");
	fflush(stdout);
	scanf("%d %d \n",&num1,&num2);	// get the two numbers from user
	sum = num1+num2;
	printf("The sum is %ld",sum);


	return 0;
}
