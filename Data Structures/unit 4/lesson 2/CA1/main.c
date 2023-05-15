/*
 * main.c
 *
 *  Created on: May 15, 2023
 *      Author: ARAFA
 */


#include "ca.h"

void setup(){
	state = STAT(waiting);
}

int main(){
	volatile int i;
	setup();
	while(1){
		state();
		for(i=0; i<1000000; i++);
	}
	return 0;
}
