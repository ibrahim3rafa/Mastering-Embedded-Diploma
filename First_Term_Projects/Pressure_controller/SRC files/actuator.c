/*
 * actuator.c
 *
 *  Created on: Jun 18, 2023
 *      Author: ARAFA
 */

#include"actuator.h"
#include"driver.h"
#include"state.h"

extern alarm_flag;
void init(){
	GPIO_INITIALIZATION ();
}
void stopAlarm(){
	Set_Alarm_actuator(1);
}
void startAlarm(){
	Set_Alarm_actuator(0);
}


STATE_Define(actuator_waiting){		//check the flag to start and stop alarm
	if(alarm_flag == 0){
		stopAlarm();
	}
	if(alarm_flag == 1){
		startAlarm();
	}
}

STATE_Define(actuator_off){
	actuator_state = STATE(actuator_waiting);
}

STATE_Define(actuator_on){
	actuator_state = STATE(actuator_waiting);
}

