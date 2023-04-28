/*
 * 8.c
 *
 *  Created on: Apr 28, 2023
 *      Author: ARAFA
 */

#include<stdio.h>
#define SIZE 5
void reverseArray(int arr[]) {		// fun to reverse array
    int i;
    for (i = 0; i < SIZE/2 ; i++) {
        int temp = arr[i];
        arr[i] = arr[SIZE-i-1];
        arr[SIZE-i-1] = temp;
    }
}
int main(){

	int arr[SIZE]={1,2,3,4,5};
	int i;
	reverseArray(arr);

	printf("Rverse manner of arr\n");
	for (i=0 ; i<SIZE ; i++){
		printf("%d ",arr[i]);
	}


	return 0;
}
