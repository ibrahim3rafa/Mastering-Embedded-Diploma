/*
 * 4.c
 *
 *  Created on: May 4, 2023
 *      Author: ARAFA
 */
#include<stdio.h>
#define SIZE 15

int main(){

	int arr[SIZE];

	int*ptr=&arr[0];
	int num;
	int i;
	printf("Enter num of elements \n");
	fflush(stdout);
	scanf("%d",&num);
	printf("ENter elenments \n");
	for(i=0 ; i<num ; i++){
		fflush(stdout);
		scanf("%d",ptr);
		ptr++;
	}
	ptr=&arr[num-1];
	printf("Array in reverse is \n");
	for(i=num-1 ;i>=0 ;i--){
		printf("%d",*ptr);
		ptr--;
	}
	return 0;
}

