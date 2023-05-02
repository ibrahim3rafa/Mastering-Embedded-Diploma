/*
 * 4.c
 *
 *  Created on: May 2, 2023
 *      Author: ARAFA
 */

#include<stdio.h>
#define SIZE 10

typedef struct Sstudent{
	unsigned short roll;
	unsigned char name[10];
	float marks;
}student;

int main(){

	student students[SIZE];
	int i;

	printf("Please Enter information of students\n");

	for(i=0 ; i<SIZE ; i++){		//get information from user
		students[i].roll = i+1;
		printf("For roll number %d\n",students[i].roll);
		printf("Enter name:");
		fflush(stdout);
		scanf("%s",students[i].name);
		printf("\nEnter Marks:");
		fflush(stdout);
		scanf("%f",&students[i].marks);
	}

	printf("Displaying information of students:\n");

	for(i=0 ; i<SIZE ;i++){
		printf("Information for roll number %d",students[i].roll);
		printf("\nName:%s",students[i].name);
		printf("\nMarks:%.1f",students[i].marks);
	}



	return 0;
}
