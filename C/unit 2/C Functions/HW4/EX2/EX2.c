/*
 * EX2.c
 *
 *  Created on: Apr 20, 2023
 *      Author: ARAFA
 */

#include<stdio.h>
long factorial(int n){
	if(n==0 || n==1){
		return 1;
	}
	return n*factorial(n-1);
}
int main(){
	int n;
	long result;
	printf("Please enter a number \n");
	fflush(stdout);
	scanf("%d",&n);		//get the number

	result = factorial(n);

	printf("Factorial of n is %ld \n",result);


	return 0;
}
