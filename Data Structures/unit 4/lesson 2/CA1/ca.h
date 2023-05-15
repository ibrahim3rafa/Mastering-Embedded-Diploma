/*
 * ca.h
 *
 *  Created on: May 15, 2023
 *      Author: ARAFA
 */

#ifndef CA_H_
#define CA_H_
#include"state.h"

extern void (*state) ();


//APIs
ST_STAT_DEF(waiting);
ST_STAT_DEF(driving);



#endif /* CA_H_ */
