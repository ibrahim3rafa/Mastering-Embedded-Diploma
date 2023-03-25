/*
 * EX7.c
 *
 *  Created on: Mar 25, 2023
 *      Author: ARAFA
 */


#include<stdio.h>
long factorial(int n){
	long fact=1;
	int i;
	if (n==0){
		fact = 1;
	}else{
		for(i=n ; i>=1 ; i--){
			fact *= i;
		}
	}
	return fact;
}

int main(){
	int n;
	long fact=0;
	do{
		printf("Please enter a positive number \n");
		fflush(stdout);
		scanf("%d",&n);
		if (n<0)
			printf("\nError!!! factorial of negative number doesn't exist\n");
	}while(n < 0);

	fact = factorial(n);


	printf("Factorial = %ld	",fact);

	return 0;
}
