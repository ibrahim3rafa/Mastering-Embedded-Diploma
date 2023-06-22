#ifndef _PSENSOR_H_
#define _PSENSOR_H_

#include "state.h"


enum {
	waiting,
	reading,
};


//APIS

void sensor_init();


STATE_Define(reading);
STATE_Define(waiting);

void (*sen_STATE)();  		//pointer to fun
#endif 
