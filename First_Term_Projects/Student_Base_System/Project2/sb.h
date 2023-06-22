/*
 * sb.h
 *
 *  Created on: Jun 18, 2023
 *      Author: ARAFA
 */

#ifndef SB_H_
#define SB_H_
#include<stdio.h>
#define SIZE 50

typedef struct {   //main struct
	int ID ;
	char name[20];
	float GPA;
	int courses[3];
}student;


//APIS
void add_student_manually();  		//function to add student
void add_student_by_ID();  		//function to add student
void find_student_by_Id();			//function to find student by roll
void find_student_by_name();		//function to find student by first name
void veiw_all_students();				//function to veiw all students
void exit_system();						//function to exit the system


#endif /* SB_H_ */
