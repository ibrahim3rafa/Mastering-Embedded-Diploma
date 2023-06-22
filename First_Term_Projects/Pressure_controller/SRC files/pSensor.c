#include"psensor.h"
#include"driver.h"
int pVal=0;
int sTimer=0;

void sensor_init(){				// Pressure Sensor initailization
	GPIO_INITIALIZATION();
}


STATE_Define(reading){
	pVal = getPressureVal();		//read the value of the sensor
	sTimer = 100;					//adjust timer to count 100
	sen_STATE(waiting);				// go to waiting state until finishing time period
}

STATE_Define(waiting){
	while(sTimer){					//stay in while loop to lose time
		sTimer--;
	}

	sTimer = 0 ;					//reset the timer
	sen_STATE(reading);				//go to reading state to get new read
}
