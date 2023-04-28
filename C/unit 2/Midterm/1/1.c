/*
 * 1.c
 *
 *  Created on: Apr 28, 2023
 *      Author: ARAFA
 */



#include<stdio.h>
int sumDigits(int num){		// function to calculate digits
	int sum = 0;
	int rem = 0;
	while(num != 0){
	rem = num%10;
	sum += rem;
	num = num/10;
	}
	return sum;
}
int main(){

	int num;
	printf("Please enter number\n");
	fflush(stdout);
	scanf("%d",&num);

	printf("Sum of digits of %d is %d ",num,sumDigits(num));

}
