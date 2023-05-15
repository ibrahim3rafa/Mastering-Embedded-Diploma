/*
 * CA.h
 *
 *  Created on: May 16, 2023
 *      Author: ARAFA
 */

#ifndef CA_H_
#define CA_H_
#include"STATE.h"

extern void (*state) ();
enum{
	US_waiting,
	CA_Driving
}CA_state_id;


//APIs

ST_STAT_DEF(US_waiting);
ST_STAT_DEF(CA_Driving);

extern void (*CA_state)();

#endif /* CA_H_ */
