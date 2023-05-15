/*
 * fifo.h
 *
 *  Created on: May 14, 2023
 *      Author: ARAFA
 */

#ifndef FIFO_H_
#define FIFO_H_
#include"stdio.h"
#include"stdint.h"

#define width 5 	//buffer width
#define element_type uint8_t	// user element type

//element_type buffer[width];  	// buffer array

typedef struct {
	uint32_t count ;
	uint32_t lenght ;
	element_type* head ;
	element_type* base ;
	element_type* tail ;
}fifo_buf;

typedef enum{    //to describe fifo status
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null
}fifo_status;

//APIs
fifo_status fifo_init(fifo_buf* fbuf , element_type* buf, uint32_t lenght);   // to intiate fifo
fifo_status fifo_enqeue(fifo_buf* fbuf , element_type item);  //to enqeue a
fifo_status fifo_deqeue(fifo_buf* fbuf , element_type* item);  //to deqeue item
fifo_status fifo_is_full(fifo_buf* fbuf); 		// to check if fifo is full
void fifo_print(fifo_buf* fbuf);		//to print fifo

#endif /* FIFO_H_ */
