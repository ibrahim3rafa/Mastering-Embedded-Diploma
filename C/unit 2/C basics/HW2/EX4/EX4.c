/*
 * EX4.c
 *
 *  Created on: Mar 25, 2023
 *      Author: ARAFA
 */

#include<stdio.h>

int main(){
	float number;

	printf("Enter a number \n");
	fflush(stdout);
	scanf("%f",&number);

	if(number > 0){
		printf("\n%0.2f is positive ",number);
	}else if(number < 0){
		printf("\n%.2f is negative",number);
	}else{
		printf("\nYou entered Zero");
	}

	return 0;
}
