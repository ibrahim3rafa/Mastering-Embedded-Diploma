/*
 * US.h
 *
 *  Created on: May 16, 2023
 *      Author: ARAFA
 */

#ifndef US_H_
#define US_H_

#include "STATE.h"

enum
{
    US_busy,
}US_state_id;

void US_Init();

ST_STAT_DEF(US_busy);

extern void (*US_state)();

#endif /* US_H_ */
