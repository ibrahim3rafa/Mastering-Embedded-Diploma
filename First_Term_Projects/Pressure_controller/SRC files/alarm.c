#include"alarm.h"
#include"state.h"
#include"driver.h"
#include"mainalgorithem.h"

unsigned int alarm_timer = 0;
int alarm_flag = 0;

void detect_high_pressure(){

	alarm_state = STATE(alarm_on);
}

STATE_Define(alarm_off){
	stopAlarm();
	alarm_flag = 0;
	alarm_state = STATE(High_Pressure_Detection);
}


STATE_Define(alarm_on){
	startAlarm();
	alarm_flag = 1;
	alarm_timer = 60 ; 	// set timer equal the period
	alarm_state = STATE(alarm_waiting); //go to waiting state

}

STATE_Define(alarm_waiting){
	while(alarm_timer){
		alarm_timer--;
	}
	alarm_timer = 0;
	stopAlarm();	//stop alarm after period end
	alarm_state = STATE(alarm_off);
}




