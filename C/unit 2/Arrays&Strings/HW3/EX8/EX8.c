/*
 * EX8.c
 *
 *  Created on: Apr 18, 2023
 *      Author: ARAFA
 */


#include<stdio.h>
#include<string.h>

#define SIZE 100

int main(){
	char str[SIZE];
	int lenght=0,i,temp;

	int j;

	printf("please enter string \n");
	fflush(stdout);
	gets(str);

	lenght = strlen(str);
	j=lenght-1;

	for(i=0 ; i<lenght/2 ; i++){
		temp = str[i];
		str[i]= str[j];
		str[j] = temp;
		j--;
	}


	printf("Reverse string is %s :",str);



	return 0;
}
