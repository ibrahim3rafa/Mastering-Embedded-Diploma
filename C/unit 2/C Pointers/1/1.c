/*
 * 1.c
 *
 *  Created on: May 4, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

int main(){
	int m = 29;
	int *ab = NULL;

	printf("Address of m is %p\n",&m);
	printf("Value of m is %d\n",m);

	ab = &m;

	printf("Now ab is assigned with the address of m.");
	printf("Address of pointer ab is : %p\n",ab);
	printf("content of ab pointer is %d \n",*ab);

	m=34;

	printf("The value of m is assigned to %d now\n",m);
	printf("Address of pointer ab is : %p\n",ab);
	printf("content of ab pointer is %d \n",*ab);

	*ab = 7;
	printf("The pointer variable ab is assigned with the value %d now\n",*ab);
	printf("Address of m is %p\n",&m);
	printf("Value of m is %d\n",m);


	return 0;
}
