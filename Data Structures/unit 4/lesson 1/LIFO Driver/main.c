/*
 * main.c
 *
 *  Created on: May 14, 2023
 *      Author: ARAFA
 */

#include<stdio.h>
#include "lifo.h"


unsigned int buffer[5] ;
int main(){
	unsigned int i , temp = 0 ;
	lifo_buf uart_lifo;
	lifo_init(&uart_lifo,buffer,5);

	for(i=0 ; i<5 ; i++){
		if( lifo_add_item(&uart_lifo,i) == lifo_no_error)
		printf("Add Item : %d \n",i);
	}

	printf("\n\n");
	for(i=0 ; i<5 ; i++){
		if(lifo_get_item(&uart_lifo,&temp) == lifo_no_error)
		printf("get Item : %d \n",temp);
	}
	return 0;
}
