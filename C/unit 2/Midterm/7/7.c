/*
 * 7.c
 *
 *  Created on: Apr 28, 2023
 *      Author: ARAFA
 */


#include<stdio.h>
int sumNumbers(int n) {		//fun to calculate sum without loop
    if (n == 1) {
        return 1;
    } else {
        return n + sumNumbers(n - 1);
    }
}
int main(){
	int n1 = 1;
	int n2 = 100;

	printf("sum between %d and %d is %d",n1,n2,sumNumbers(n2));
	return 0;
}
