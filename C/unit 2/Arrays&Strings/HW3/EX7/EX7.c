/*
 * EX7.c
 *
 *  Created on: Apr 18, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

#define SIZE 100

int main(){

	char str[SIZE];
	int lenght=0;
	int i;
	printf("Enter the string \n");
	fflush(stdout);
	gets(str);

	for(i=0 ; str[i]!='\0' ; i++){
		lenght++;
	}


	printf("Lenght of string is %d ",lenght);

	return 0;
}
