/*
 * lifo.c
 *
 *  Created on: May 14, 2023
 *      Author: ARAFA
 */

#include "lifo.h"


// APIs
buf_status lifo_add_item(lifo_buf* lbuf, unsigned int item){
	//check if valid
	if(!lbuf->base|| !lbuf->head)
		return lifo_null;
	//check if full
	if(lbuf->count == lbuf->lenght)
		return lifo_full;
	//add item
	*(lbuf->head) = item;
	lbuf->head++;
	lbuf->count++;
	return lifo_no_error;

}
buf_status lifo_get_item(lifo_buf* lbuf, unsigned int *item){
	//check if valid
	if(!lbuf->base|| !lbuf->head)
		return lifo_null;
	//check if empty
	if(lbuf->count == 0)
		return lifo_empty;
	//get the value
	lbuf->head--;
	*(item) = *(lbuf->head);
	lbuf->count--;
	return lifo_no_error;
}
buf_status lifo_init(lifo_buf* lbuf , unsigned int* buff,unsigned int lenght){
	//check if valid
	if(buff == NULL)
		return lifo_null;

	//initiate conditions
	lbuf->base = buff;
	lbuf->head = buff;
	lbuf->count = 0;
	lbuf->lenght = lenght;
	return lifo_no_error;
}
