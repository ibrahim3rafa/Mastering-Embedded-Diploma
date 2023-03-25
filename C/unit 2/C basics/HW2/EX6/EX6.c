/*
 * EX.c
 *
 *  Created on: Mar 25, 2023
 *      Author: ARAFA
 */

#include<stdio.h>

int main(){
	int i,num;
	long sum=0;
	printf("Please enter a natural number \n");
	fflush(stdout);
	scanf("%d",&num);

	for(i=num ; i>=0 ; i--){

		sum += i;
	}

	printf("\nSum is = %ld",sum);

	return 0;
}
