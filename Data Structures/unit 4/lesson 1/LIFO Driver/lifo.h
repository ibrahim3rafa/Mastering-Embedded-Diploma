/*
 * lifo.h
 *
 *  Created on: May 14, 2023
 *      Author: ARAFA
 */

#ifndef LIFO_H_
#define LIFO_H_
#include<stdlib.h>
#include<stdio.h>

/*lifo buffer structure*/
typedef struct{
	unsigned int * head ;
	unsigned int *base ;
	unsigned int count ;
	unsigned int lenght ;
}lifo_buf;

//lifo status
typedef enum{
	lifo_no_error,
	lifo_full,
	lifo_empty,
	lifo_null
}buf_status;

// APIs
buf_status lifo_add_item(lifo_buf* lbuf, unsigned int item);
buf_status lifo_get_item(lifo_buf* lbuf, unsigned int *item);
buf_status lifo_init(lifo_buf* lbuf , unsigned int* buff,unsigned int lenght);

#endif /* LIFO_H_ */
