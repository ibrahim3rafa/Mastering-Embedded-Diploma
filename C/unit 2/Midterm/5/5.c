/*
 * 5.c
 *
 *  Created on: Apr 28, 2023
 *      Author: ARAFA
 */

#include<stdio.h>
int onesNumInNumber(int num){		// fun to count ones num
	int i;
	int sum=0 ;
	for(i=31 ; i>=0 ; i--){
		if(num & (1<<i)){
			printf("1");
			sum++;
		}else{
			printf("0");
		}
	}
	printf("\n");
	return sum;
}
int main(){
	int num;
	int ones_num=0;
	printf("Please enter the number \n");
	fflush(stdout);
	scanf("%d",&num);
	printf("Binary of %d is \n",num);
	ones_num=onesNumInNumber(num);
	printf("Num of ones in %d is %d",num,ones_num);
	return 0;
}
