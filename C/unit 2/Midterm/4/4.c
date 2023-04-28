/*
 * 4.c
 *
 *  Created on: Apr 28, 2023
 *      Author: ARAFA
 */


#include<stdio.h>
int reverseDigits(int num){
	int rem = 0 ;
	int new_num=0;
	while(num != 0){

		rem = num%10 ;
		new_num = new_num*10 + rem;
		num = num/10;

	}
	return new_num;
}
int main(){
	int num;
	printf("Please enter number to reverse digits\n");
	fflush(stdout);
	scanf("%d",&num);

	printf("%d in reversed manner is %d ",num,reverseDigits(num));


	return 0;
}
