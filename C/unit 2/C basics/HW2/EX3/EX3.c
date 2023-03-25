/*
 * EX3.c
 *
 *  Created on: Mar 25, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

int main(){

	float n1,n2,n3;
	float largest;

	printf("Please enter the first number \n");
	fflush(stdout);
	scanf("%f",&n1);

	printf("Please enter the second number \n");
	fflush(stdout);
	scanf("%f",&n2);

	printf("Please enter the third number \n");
	fflush(stdout);
	scanf("%f",&n3);

	largest = n1;

	if(n2>n1 && n2>n3){
		largest = n2;
	}else if(n3>n1 && n3>n2){
		largest = n3;
	}

	printf("\nlargest num is %0.2f	 ",largest);
	return 0;
}
