/*
 * EX5.c
 *
 *  Created on: Mar 25, 2023
 *      Author: ARAFA
 */


#include<stdio.h>


int main(){
	char ch;

	printf("Enter a charcter : ");
	fflush(stdout);
	scanf("%c",&ch);

	if((ch>=65 && ch<= 90) || (ch>=97 && ch<=122)){

		printf("\n %c is an alphabet",ch);

	}else{
		printf("\n %c is not an alphabet",ch);
	}
	return 0;
}
