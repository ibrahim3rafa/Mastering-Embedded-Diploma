/*
 * mainalgorithem.c
 *
 *  Created on: Jun 17, 2023
 *      Author: ARAFA
 */

#include "mainalgorithem.h"
#include "driver.h"
#include "state.h"

int pVal = 0;
int threshold = 20 ;

void get_pVal(){		//function to get pVal
	pVal = getPressureVal();
}

STATE_Define(High_Pressure_Detection){
	get_pVal();
	if(pVal <= threshold){
		get_pVal();
		algo_state = STATE(High_Pressure_Detection);
	}else{
		detectHighPressure();		//return back to dectet high pressure state
		get_pVal();
		algo_state = STATE(High_Pressure_Detection);
	}
}

