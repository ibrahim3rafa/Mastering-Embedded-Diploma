/*
 * EX4.c
 *
 *  Created on: Apr 20, 2023
 *      Author: ARAFA
 */


#include<stdio.h>
long power(int num, int pow){
	if(pow != 0){
		return num*power(num,pow-1);
	}else {
		return 1;
	}
}
int main(){
	int num,pow;
	long result =1;
	printf("please enter base number\n");
	fflush(stdout);
	scanf("%d",&num);
	printf("please enter power\n");
	fflush(stdout);
	scanf("%d",&pow);

	result=power(num,pow);

	printf("%d^%d = %ld",num,pow,result);
	return 0;
}
