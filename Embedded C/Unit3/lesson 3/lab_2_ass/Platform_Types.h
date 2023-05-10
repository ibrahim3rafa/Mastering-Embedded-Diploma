/*
 * Platform_Types.h
 *
 *  Created on: May 8, 2023
 *      Author: ARAFA
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

typedef enum boolean{
	FALSE,TRUE
}bool;


typedef unsigned char		        	uint8;
typedef signed char			  	        sint8;
typedef unsigned short		    	    uint16;
typedef signed short				    sint16;
typedef unsigned long					uint32;
typedef signed long						sint32;
typedef unsigned long long 				uint64;
typedef signed long long 				sint64;
typedef float 							float32;
typedef double							float64;


typedef volatile unsigned char								vuint8;
typedef volatile signed char 								vsint8;
typedef volatile unsigned short								vuint16;
typedef volatile signed short								vsint16;
typedef volatile unsigned long 								vuint32;
typedef volatile signed long								vsint32;
typedef volatile unsigned long long 						vuint64;
typedef volatile signed long			         			vsint64;






#endif /* PLATFORM_TYPES_H_ */
