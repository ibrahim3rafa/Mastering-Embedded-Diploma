#ifndef _ALARM_H_
#define _ALARM_H_
#include"state.h"

enum{
	alarm_off,
	alarm_on,
	alarm_waiting,
};

STATE_Define(alarm_off);
STATE_Define(alarm_on);
STATE_Define(alarm_waiting);

void (*alarm_state)();		//ptr to function to no arguments and return void


#endif
