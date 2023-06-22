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
//#define STATE(_stat_function_) ST_##_stat_function_

#define STATE_Define(_stat_function_) void ST_##_stat_function_()
#define STATE(_stat_function_) ST_##_stat_function_()


void get_pVal();
void detectHighPressure();
void startAlarm();
void stopAlarm();
#endif /* STATE_H_ */
