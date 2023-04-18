/*
 * EX6.c
 *
 *  Created on: Apr 18, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

#define SIZE 100

int main(){
	char str[SIZE];
	char c;
	int i;
	int count=0;
	printf("Enter a string : ");
	fflush(stdout);
	gets(str);

	printf("Enter a character to find frequency : \n");
	fflush(stdout);
	scanf("%c",&c);

	for(i=0 ; str[i]!='\0' ; i++){
		if(str[i] == c)
			count++;
	}


	printf("Frequency of %c is %d",c,count);

	return 0;
}
