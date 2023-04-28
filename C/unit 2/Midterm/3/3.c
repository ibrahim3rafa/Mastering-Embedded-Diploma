/*
 * 3.c
 *
 *  Created on: Apr 28, 2023
 *      Author: ARAFA
 */


#include<stdio.h>
int checkPrime(int num){	// fun. to check prime
	int i;
	unsigned char flag = 0;
	for(i=2 ; i<=num/2 ; i++){
		if(num%i == 0){
			flag = 1;
		}
	}
	return flag;
}
int main(){
	int n1;
	int n2;
	int i;
	int flag_res;
	printf("Please enter the two numbers\n");
	fflush(stdout);
	scanf("%d %d",&n1,&n2);

	printf("Prime numbers between %d and %d is ",n1,n2);

	for(i=n1 ; i<=n2 ;i++){
		flag_res=checkPrime(i);

		if(flag_res == 0){
			printf("%d ",i);
		}else{
			continue;
		}
	}


	return 0;
}
