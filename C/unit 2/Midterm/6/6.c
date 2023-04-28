/*
 * 6.c
 *
 *  Created on: Apr 28, 2023
 *      Author: ARAFA
 */


#include<stdio.h>
#define SIZE 7
int uniqueNumInArr(int arr[]){		//func. to get unique
	int result = arr[0];
	for (int i = 1; i < SIZE; i++) {
		result ^= arr[i];
	}
	return result;
}
int main(){
	int arr[SIZE];
	int i;
	int res ;
	printf("Enter arr\n");
	fflush(stdout);
	for(i=0 ; i<SIZE ; i++){
		fflush(stdout);
		scanf("%d",&arr[i]);
	}

	res = uniqueNumInArr(arr);

	printf("The unique number is %d",res);



	return 0;
}
