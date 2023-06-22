/*
 * mainalgorithem.h
 *
 *  Created on: Jun 17, 2023
 *      Author: ARAFA
 */

#ifndef MAINALGORITHEM_H_
#define MAINALGORITHEM_H_
#include"state.h"

enum{

	High_Pressure_Detection
};

STATE_Define(High_Pressure_Detection);

void (*algo_state)();

#endif /* MAINALGORITHEM_H_ */
