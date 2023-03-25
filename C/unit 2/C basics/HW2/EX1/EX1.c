/*
 * EX1.c
 *
 *  Created on: Mar 25, 2023
 *      Author: ARAFA
 */

#include<stdio.h>

int main(){
	int num;
	printf("Please enter an integer you want to check :");
	fflush(stdout);
	scanf("%d",&num);

	if ((num % 2) == 0){
		printf("\n%d is even",num);
	}else{
		printf("\n%d is odd",num);
	}

	return 0;
}
