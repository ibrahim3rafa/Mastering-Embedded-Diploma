/*
 * main.c
 *
 *  Created on: May 14, 2023
 *      Author: ARAFA
 */
#include "fifo.h"


int main(){
	element_type buffer[width];  	// buffer array

	fifo_buf uart_buf;
	element_type i, temp = 0;

	if(fifo_init(&uart_buf,buffer, width) == fifo_no_error)
		printf("======= Initialization success========");
	else
		printf("======= Initialization failed========");

	for(i=0 ; i<width ; i++){
		printf("\nAdd enqeue %x",i);
		if(fifo_enqeue(&uart_buf, i) == fifo_no_error)
			printf("\nfifo enqeue done");
		else
			printf("\nfifo enqeue failed");

	}
	fifo_print(&uart_buf);		//printf fifo afer enqeue

	if(fifo_deqeue(&uart_buf, &temp) == fifo_no_error)		// deqeue first elemet
		printf("\n deqeue %x done ",temp);
	if(fifo_deqeue(&uart_buf, &temp) == fifo_no_error)   	// deqeue second elemet
		printf("\n deqeue %x done\n",temp);

	fifo_print(&uart_buf);			//print again after deqeuing the 2 elemets
	return 0;
}

