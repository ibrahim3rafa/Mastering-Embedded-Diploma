/*
 * 5.c
 *
 *  Created on: May 2, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

#define PI 3.14
#define AREA(r) ((PI)*(r)*(r))

int main()
{
	int r;
	float area;

	printf("Enter radius");
	fflush(stdout);
	scanf("%d",&r);

	area=AREA(r);

	printf("Area is %.1f",area);



	return 0;
}
