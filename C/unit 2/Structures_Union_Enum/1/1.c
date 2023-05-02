/*
 * 1.c
 *
 *  Created on: May 1, 2023
 *      Author: ARAFA
 */


#include<stdio.h>

struct Sstudent{
	unsigned char name[50];
	unsigned int roll;
	float marks;
}student;

int main(){


	printf("Enter Name:");
	fflush(stdout);
	gets(student.name);

	printf("\n Enter roll:");
	fflush(stdout);
	scanf("%d",&student.roll);

	printf("Enter Marks: ");
	fflush(stdout);
	scanf("%f",&student.marks);

	printf("name : %s \nRoll: %d \nmarks:%f \n",student.name,student.roll,student.marks);


	return 0;
}
