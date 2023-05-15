/*
 * state.h
 *
 *  Created on: May 15, 2023
 *      Author: ARAFA
 */

#ifndef STATE_H_
#define STATE_H_
#include<stdio.h>
#include<stdlib.h>

#define ST_STAT_DEF(_stat_function_) void ST_##_stat_function_()
#define STAT(_stat_function_) ST_##_stat_function_


extern void (*state) ();


#endif /* STATE_H_ */
