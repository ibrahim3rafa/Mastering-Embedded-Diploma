/*
 * EX2.c
 *
 *  Created on: Mar 25, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

int main(){
	char ch;

	printf("Enter an alphabet : ");
	fflush(stdout);
	scanf("%c",&ch);

	switch(ch){
	case 'A':
	case 'a':
		printf("\n%c is vowel. ",ch);
			break;
	case 'E':
	case 'e':
		printf("\n%c is vowel. ",ch);
			break;
	case 'I':
	case 'i':
		printf("\n%c is vowel. ",ch);
			break;
	case 'O':
	case 'o':
		printf("\n%c is vowel. ",ch);
			break;
	case 'U':
	case 'u':
		printf("\n%c is vowel. ",ch);
			break;
	default:
		printf("\n%c is consonant\n ",ch);
	}


	return 0;
}
