/*
 * EX4.c
 *
 *  Created on: Apr 18, 2023
 *      Author: ARAFA
 */


#include<stdio.h>
#define SIZE 10

int main(){
	int arr[SIZE];
	int lenght;
	int location;
	int element;
	int i;

	printf("Please enter the lenght\n"); 	// get the lenght from user
	fflush(stdout);
	scanf("%d",&lenght);

	printf("Please enter the array elements \n");		// get the array elements
	for(i=0 ; i<lenght ; i++){
		fflush(stdout);
		scanf("%d",&arr[i]);
	}

	printf("Please enter the element to be inserted \n");		// get the element
	fflush(stdout);
	scanf("%d",&element);

	printf("Please enter location \n"); 	//get the location
	fflush(stdout);
	scanf("%d",&location);

	for(i=0 ; i<=lenght ; i++){
		if(i==location-1){			// check if reached loction
			for(i=lenght ; i>=location ; i--){   	//inner loop to shift each element
				arr[i] = arr[i-1];
			}
			arr[i] = element; 		// put the element
		}
	}

	// loop to print array after inserting element
	for(i=0 ; i<=lenght; i++){
		printf("%d",arr[i]);
	}

}
