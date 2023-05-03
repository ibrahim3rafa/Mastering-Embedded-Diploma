/*
 * 2.c
 *
 *  Created on: May 4, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

int main(){

	char alph[27];

	int i;

	char*ptr = alph;

	for (i=0 ; i<26 ; i++){

		*ptr= (i + 'A');
		ptr++;
	}

	ptr = alph;
	printf("Alphabits\n");

	for (i=0 ; i<26 ; i++){

		printf("%c ",*ptr);
		ptr++;

	}

	return 0;
}
