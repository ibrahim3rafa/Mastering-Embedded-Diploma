/*
 * 3.c
 *
 *  Created on: May 4, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

int main(){
	char str[10] ;
	int len = 0;
	char *ptr= NULL;
	int i;
	printf("Enter String \n");
	fflush(stdout);
	gets(str);
	len = strlen(str);
	ptr =str + len -1;

	printf("The string in reverse is \n");

	for (i=0 ; i<len; i++ ){

		printf("%c ",*ptr);
		ptr--;
	}

	return 0;
}
