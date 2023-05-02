/*
 * 2.c
 *
 *  Created on: May 1, 2023
 *      Author: ARAFA
 */
#include<stdio.h>
struct Sdistance{
	int feet;
	float inch;
}a,b,sum;
int main(){
	printf("Enter information for 1st distance\n");
	printf("Enter feet:");
	fflush(stdout);
	scanf("%d",&a.feet);
	printf("\nEnter inch:");
	fflush(stdout);
	scanf("%f",&a.inch);

	printf("Enter information for 2nd distance\n");
	printf("Enter feet:");
	fflush(stdout);
	scanf("%d",&b.feet);
	printf("\nEnter inch:");
	fflush(stdout);
	scanf("%f",&b.inch);

	sum.feet = a.feet + b.feet;
	sum.inch = a.inch + b.inch;

	if(sum.inch >= 12){
		sum.feet++;
		sum.inch -= 12;
	}

	printf("sum of distance is %d' %.1f\" ",sum.feet, sum.inch );
	return 0;
}

