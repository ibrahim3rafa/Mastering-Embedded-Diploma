/*
 * fifo.c
 *
 *  Created on: May 14, 2023
 *      Author: ARAFA
 */
#include "fifo.h"



//APIs
fifo_status fifo_init(fifo_buf* fbuf , element_type* buf, uint32_t lenght)   // to intiate fifo
{
	//check if fifo valid
	if(buf == NULL)
		return fifo_null;

	//intialization conditions  (make all pointers point to base at first)
	fbuf->head = buf;
	fbuf->base = buf;
	fbuf->tail = buf;
	fbuf->count = 0; 	//set count  = 0 at first
	fbuf->lenght = width;		// set lenght = width at first

	return fifo_no_error;
}

fifo_status fifo_enqeue(fifo_buf* fbuf , element_type item)  //to enqeue a
{
	//check if fifo is valid
	if(!fbuf->base || !fbuf->head || !fbuf->tail)
		return fifo_null;

	//check if fifo is full
	if(fifo_is_full(fbuf) == fifo_full)
		return fifo_full;

	//enqeue new item
	*(fbuf->head) = item;
	fbuf->count++;		//icrement count
	//check if fifo is full
	if (fbuf->head == fbuf->base+(width*sizeof(element_type))){
		fbuf->head = fbuf->base;   //circler mode
	}else{
		fbuf->head++;		//increment head ptr
	}
	return fifo_no_error;

}
fifo_status fifo_deqeue(fifo_buf* fbuf , element_type* item)  //to deqeue item
{
	//check if fifo is valid
	if(!fbuf->base || !fbuf->head || !fbuf->tail)
		return fifo_null;
	// check if fifo is empty
	if(fbuf->count == 0)
		return fifo_empty;
	//deqeue element
	*(item) = *(fbuf->tail);
	fbuf->count--;		//decremet count
	//check if fifo is full
	if (fbuf->tail == fbuf->base+(width*sizeof(element_type))){
		fbuf->tail = fbuf->base;   //circler mode
	}else{
		fbuf->tail++;		//increment tail ptr
	}
	return fifo_no_error;

}

fifo_status fifo_is_full(fifo_buf* fbuf) 		// to check if fifo is full
{
	//check if fifo is valid
	if(!fbuf->base || !fbuf->head || !fbuf->tail)
		return fifo_null;

	if(fbuf->count == fbuf->lenght)
		return fifo_full;
	return fifo_no_error;

}
void fifo_print(fifo_buf* fbuf)		//to print fifo
{
	element_type* temp ;
	unsigned int i;
	//check if fifo is valid
	if(!fbuf->base || !fbuf->head || !fbuf->tail)
		printf("The fifo does not exist");

	// check if fifo is empty
	if(fbuf->count == 0){
		printf("Fifo is empty");
	}else{
		//print FIFO
				temp = fbuf->tail;
				printf("------FIFO print------\n");
				for(i=0;i<fbuf->count;i++)
				{
					printf("\t %x \n",*temp);
					temp++;
				}

				printf("----------------------\n");
		}
	}



