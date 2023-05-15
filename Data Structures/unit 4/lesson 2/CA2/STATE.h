/*
 * STATE.h
 *
 *  Created on: May 16, 2023
 *      Author: ARAFA
 */

#ifndef STATE_H_
#define STATE_H_

#include<stdio.h>
#include<stdlib.h>

#define ST_STAT_DEF(_stat_function_) void ST_##_stat_function_()
#define STAT(_statFUN) ST_##_statFUN


void US_Set_distance(int distance);
void DC_Set_motor(int speed);

#endif /* STATE_H_ */
