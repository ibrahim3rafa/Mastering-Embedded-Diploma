#include <stdint.h>
#include <stdio.h>
#include"state.h"
#include "driver.h"
#include"psensor.h"
#include"alarm.h"
#include"mainalgorithem.h"
#include"actuator.h"

void setup(){
	init();
	sensor_init();
	alarm_state = STATE(alarm_off);
	sen_STATE = STATE(reading);
	algo_state = STATE(High_Pressure_Detection);
	stopAlarm();
	actuator_state = STATE(actuator_waiting);
}
int main (){
	GPIO_INITIALIZATION();
	setup();
	while (1)
	{
		sen_STATE();
		algo_state();
		alarm_state();
		actuator_state();
		Delay(1000);

	}

}
