/*
 * DC.h
 *
 *  Created on: May 16, 2023
 *      Author: ARAFA
 */

#ifndef DC_H_
#define DC_H_

#include "STATE.h"
enum
{
    DC_idle,
    DC_busy
}DC_state_id;

ST_STAT_DEF(DC_idle);
ST_STAT_DEF(DC_busy);

void DC_Init();

extern void (*DC_state)();

#endif /* DC_H_ */
