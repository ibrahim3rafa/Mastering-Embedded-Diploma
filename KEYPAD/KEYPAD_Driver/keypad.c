/*
 * keypad.c
 *
 *  Created on: Jul 30, 2023
 *      Author: ARAFA
 */


#include  "keypad.h"

int keypadRow[] = {R0 , R1 , R2 , R3};
int keypadColumn[] = {C0 , C1 , C2 , C3};

void KEYPAD_init(){
	KEYPAD_PORT_DIR &=~((1<<keypadRow[0]) | (1<<keypadRow[1]) | (1<<keypadRow[2]) | (1<<keypadRow[3]));
	KEYPAD_PORT_DIR |=((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));
	KEYPAD_PORT = 0xFF;

}
char KEYPAD_getKey(void){
	int i , j ;

	for (i=0 ; i<4 ; i++){
		KEYPAD_PORT |=((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));
		KEYPAD_PORT &= ~(1<<keypadColumn[i]);

		for(j=0 ; j<4 ; j++){
			if(!(KEYPAD_PORT_PIN & (1<<keypadRow[j])));
			while(!(KEYPAD_PORT_PIN & (1<<keypadRow[j])));
			switch (i) {
			case (0):
									if(j == 0) return '7';
									else if (j == 1 ) return '4';
									else if (j == 2) return '1' ;
									else if (j == 3 ) return '?';
			break;

			case (1):
									if(j == 0) return '8';
									else if (j == 1 ) return '5';
									else if (j == 2) return '2' ;
									else if (j == 3 ) return '0';
			break;

			case (2):
									if(j == 0) return '9';
									else if (j == 1 ) return '6';
									else if (j == 2) return '3' ;
									else if (j == 3 ) return '=';
			break;

			case (3):
									if(j == 0) return '/';
									else if (j == 1 ) return '*';
									else if (j == 2) return '-' ;
									else if (j == 3 ) return '+';
			break;
			}
		}

	}
	return 'A';
}
