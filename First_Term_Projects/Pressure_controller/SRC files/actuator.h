/*
 * actuator.h
 *
 *  Created on: Jun 18, 2023
 *      Author: ARAFA
 */

#ifndef ACTUATOR_H_
#define ACTUATOR_H_

void init();


enum{
	actuator_off,
	actuator_on,
	actuator_waiting,
};


void (*actuator_state)();

#endif /* ACTUATOR_H_ */
