/*
 * DC.c
 *
 *  Created on: May 16, 2023
 *      Author: ARAFA
 */


#include "DC.h"
/*Variables*/
int DC_speed = 0;

/*State Pointer to fun */
void (*DC_state)();

void DC_Init()
{
    printf("DC_Init\n");
}
void DC_Set_motor(int speed)
{
    DC_speed = speed;
    DC_state = STAT(DC_busy);
    printf("CA Send Speed to DC equal : %d\n",DC_speed);
}

ST_STAT_DEF(DC_idle)
{
    DC_state_id = DC_idle;
    printf("DC_idle state: speed= %d \n",DC_speed);
}

ST_STAT_DEF(DC_busy)
{
    DC_state_id = DC_busy;
    DC_state = STAT(DC_idle);
    printf("DC_busy state: speed= %d \n",DC_speed);

}
