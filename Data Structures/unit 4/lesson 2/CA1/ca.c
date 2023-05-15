/*
 * ca.c
 *
 *  Created on: May 15, 2023
 *      Author: ARAFA
 */


#include"ca.h"

//variables
int speed = 0;
int distance = 0;
int threshold = 50 ;
int US_Get_Distance_Random(int l, int r);
void (*state) ();


 enum {
	CA_waiting,
	CA_driving
}CA_state_id;

ST_STAT_DEF(waiting){

	//check state
	CA_state_id = CA_waiting;
	//speed
	speed = 0;
	//get randoim distance
	distance = US_Get_Distance_Random(45,55);

	(distance<=threshold)? (state=STAT(waiting)) : (state=STAT(driving));
	printf("Waiting state: distance=%d speed=%d \n",distance, speed);
}
ST_STAT_DEF(driving){
	//check state
	CA_state_id = CA_driving;
		//speed
		speed = 30;
		//get randoim distance
		distance = US_Get_Distance_Random(45,55);

		(distance<=threshold)? (state = STAT(waiting)) : (state = STAT(driving));
		printf("driving state: distance=%d speed=%d \n",distance, speed);
}


int US_Get_Distance_Random(int l, int r){
	int rand_num = (rand() % (r-l+1))+l;
	return rand_num;
}
