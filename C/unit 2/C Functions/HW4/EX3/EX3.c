/*
 * EX3.c
 *
 *  Created on: Apr 20, 2023
 *      Author: ARAFA
 */
#include <stdio.h>
void reverseSentence();
int main() {
	printf("Enter a sentence: ");
	reverseSentence();
	return 0;
}

void reverseSentence() {
	char c;
	fflush(stdout);
	scanf("%c", &c);
	if (c != '\n') {
		reverseSentence();
		printf("%c", c);
	}
}
