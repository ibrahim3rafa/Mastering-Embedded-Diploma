/*
 * CA.c
 *
 *  Created on: May 16, 2023
 *      Author: ARAFA
 */


#include "CA.h"

/*Variables*/
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;



/*State Pointer to fun */
void (*CA_state)();

void US_Set_distance(int distance)
{
    CA_distance = distance;
    (CA_distance <= CA_threshold) ? (CA_state = STAT(US_waiting)) : (CA_state = STAT(CA_Driving));
    printf("US Send Distance to CA equal : %d\n",CA_distance);
}

ST_STAT_DEF(US_waiting)
{
    CA_state_id = US_waiting;
    printf("US_waiting state: distance = %d , speed = %d \n",CA_distance,CA_speed);
    CA_speed = 0;
    DC_Set_motor(CA_speed);
}

ST_STAT_DEF(CA_driving)
{
    CA_state_id = CA_Driving;
    printf("CA_driving state: distance = %d , speed = %d \n",CA_distance,CA_speed);
    CA_speed = 30;
    DC_Set_motor(CA_speed);
}
