/*
 * sb.c
 *
 *  Created on: Jun 18, 2023
 *      Author: ARAFA
 */
#include"sb.h"
#include"string.h"
int i = 0;
student s[SIZE]; 		//store for 50 student

//APIS
void add_student_manually() 		//function to add student
{
	int j  ;
	// get the information of the student from user
	printf("please enter the student name\n ");
	gets(s[i].name);
	printf("\n please enter the student id\n");
	fflush(stdout);
	scanf("%d",&s[i].ID);
	printf("please enter the student GPA\n");
	scanf("%f\n",&s[i].GPA);
	printf("please enter the student courses\n");
	for( j = 0 ; j<3 ; j++){
		printf("course number %d\n",i+1);
		scanf("%d",&s[i].courses[j]);
	}
	i++;
}
void add_student_by_ID() //function to add student
{
	printf("please enter the student Id\n");
	scanf("%d",&s[i].ID);
	printf("please enter the student name\n ");
	gets(s[i].name);
	printf("please enter the student GPA\n");
	scanf("%f\n",&s[i].GPA);
	printf("please enter the student courses\n");
	for(int j = 0 ; j<3 ; j++){
		printf("course number %d\n",j+1);
		scanf("%d",&s[i].courses[j]);
	}
	i++;
}

void find_student_by_Id()			//function to find student by roll
{
	int k;
	printf("Please enter id \n");
	scanf("%d",&k);
	for(i=0 ; i<=k ; i++){  //inner loop to search about student
		if(s[i].ID == s[k].ID){
			printf("student name is %s\n",s[i].name);
			printf("student id is %d\n",s[i].ID);
			printf("student courses is \n");
			for(int j = 0 ; j<3 ; j++){
				printf("course number %d is %d\n",j+1,s[k].courses[j]);
			}
		}
	}
}


void find_student_by_name()		//function to find student by first name
{
	char name_search[20];
	int k;
	printf("please enter student name\n");
	gets(name_search);
	for (k=0; k<=i ; k++){   //inner loop to search for name

		if(strcmp(s[k].name,name_search) == 0){
			printf("student name is %s\n",s[i].name);
			printf("student id is %d\n",s[i].ID);
			printf("student courses is \n");
			for(int j = 0 ; j<3 ; j++){
				printf("course number %d is %d\n",j+1,s[k].courses[j]);
			}

		}
	}

}

void veiw_all_students()				//function to veiw all students
{
	printf("the student details are \n");
	for(int j=0  ; j<=i  ; j++ ){
		printf("student name is %s\n",s[j].name);
		printf("student id is %d\n",s[j].ID);
		printf("student courses is \n");
		for(int k = 0 ; k<3 ; k++){
			printf("course number %d is %d\n",j+1,s[k].courses[j]);
		}
	}
}
void exit_system()						//function to exit the system
{
	printf("you are leaving thank you\n");
}
