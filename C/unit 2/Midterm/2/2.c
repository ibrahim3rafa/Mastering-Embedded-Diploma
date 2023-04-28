/*
 * 2.c
 *
 *  Created on: Apr 28, 2023
 *      Author: ARAFA
 */


#include<stdio.h>
#include<math.h>

float sqrtOfNum(int num){ 	//fun to calculate sqrt
	return sqrt(num);
}
int main(){
	int num;

	printf("Please enter the num \n");
	fflush(stdout);
	scanf("%d",&num);

	printf("sqrt of %d is %0.3f ",num,sqrtOfNum(num));

	return 0;
}
