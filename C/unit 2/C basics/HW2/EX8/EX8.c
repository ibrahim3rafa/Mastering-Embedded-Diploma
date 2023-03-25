/*
 * EX8.c
 *
 *  Created on: Mar 25, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

int main(){
	char operator ;
	float operand1,operand2;
	double result=0;
	printf("Enter operator either + or - or * or divide:");
	fflush(stdout);
	scanf("%c",&operator);

	printf("\nEnter two operands : ");
	fflush(stdout);
	scanf("%f",&operand1);
	fflush(stdout);
	scanf("%f",&operand2);

	switch(operator) {
	case '+':
		result = operand1 + operand2;
		printf("%.1f %c %.1f = %.1f",operand1,operator,operand2,result);
			break;
	case '-':
		result = operand1 - operand2;
		printf("%.1f %c %.1f = %.1f",operand1,operator,operand2,result);
			break;
	case '*':
		result = operand1 * operand2;
		printf("%.1f %c %.1f = %.1f",operand1,operator,operand2,result);
			break;
	case '/':
		result = operand1 / operand2;
		printf("%.1f %c %.1f = %.1f",operand1,operator,operand2,result);
			break;


	}

}
