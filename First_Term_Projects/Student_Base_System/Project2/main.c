/*
 * main.c
 *
 *  Created on: Jun 18, 2023
 *      Author: ARAFA
 */

#include"sb.h"
#include<stdio.h>

void main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);


	int n1;
	printf("Welcome to the student base system\n");
	while(1){
		printf("please choose one option \n");
		printf("choose 1 to add a student manually \n");
		printf("choose 2 to add student by ID\n");
		printf("choose 3 to find student by id\n");
		printf("choose 4 to find student by name\n");
		printf("choose 5 to view all students\n");
		printf("choose 6 exit system \n");
		scanf("%d",&n1);

		switch(n1){
		case 1 :
			add_student_manually();
				break;
		case 2 :
			add_student_by_ID();
				break;

		case 3 :
			find_student_by_Id();
				break;

		case 4 :
			find_student_by_name();
				break;

		case 5 :
			veiw_all_students();
				break;

		case 6 :
			exit_system();
				break;


		}
	}
return ;
}
