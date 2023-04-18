/*
 * EX5.c
 *
 *  Created on: Apr 18, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

#define SIZE 10

int main(){
	int n;
	int i;
	int element;

	int arr[SIZE];

	printf("Please enter the number of elements \n");	//get elements number
	fflush(stdout);
	scanf("%d",&n);

	printf("Enter the array elements"); 	//loop to get array
	for(i=0 ; i<n ; i++){
		fflush(stdout);
		scanf("%d",&arr[i]);
	}

	printf("Please enter the element to be searched\n");	// get element to be searched
	fflush(stdout);
	scanf("%d",&element);

	for(i=0 ; i<n; i++){		// loop to search about element
		if(arr[i] == element){
			printf("Element found at location %d",i+1);
		}
	}

	return 0;
}
