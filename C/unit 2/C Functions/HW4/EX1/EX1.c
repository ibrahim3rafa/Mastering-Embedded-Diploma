/*
 * EX1.c
 *
 *  Created on: Apr 20, 2023
 *      Author: ARAFA
 */

#include<stdio.h>
int checkPrime(int i){		//function to get prime

	int j;
	int flag = 0;

	for(j=2 ; j<=i/2 ; j++){
		if(i%j == 0){
			flag=1;
			break;
		}
	}
	return flag;
}

int main(){
	int x,i,y;
	int flag;

	printf("Enter two number(intervals)\n");
	fflush(stdout);
	scanf("%d %d",&x,&y);// get the numbers
	printf("Prime numbers between %d and %d are:",x,y);

	for (i=x ; i<=y ; i++){		//loop on the interval
		flag = checkPrime(i);
		if(flag == 0){
			printf("%d ",i);
		}
	}


	return 0;
}
