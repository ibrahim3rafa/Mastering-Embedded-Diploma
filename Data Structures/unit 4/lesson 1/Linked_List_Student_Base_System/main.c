/*
 * main.c
 *
 *  Created on: May 14, 2023
 *      Author: ARAFA
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct Sdata {		//struct to store information for the student
	unsigned char Name[40];
	unsigned int ID ;
	float Height;
};

struct Sstudent{	//Node to store students
	struct Sdata student;
	struct Sstudent* Nextstudent;
};

struct Sstudent* Headstudent = NULL;
struct Sstudent* Currentstudent = NULL;
struct Sstudent* Prevstudent = NULL;


void create_NewRecord(struct Sstudent* Newstudent);
void add_Student();
void view_Students();
void delete_Students();
void delete_AllStudents();
void get_NthStudentFromEnd();
void get_MiddleNode();
void reverse_Records();
void Exit();

unsigned int Flag = 1;
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	while(Flag == 1){
		unsigned char temp_option[10];
		printf("\nWelcome to my student data base system\n");
		printf("========================================\n");
		printf("Please choose from following options\n");
		printf("1 : Add new student\n");
		printf("2 : Delete Students\n");
		printf("3 : View Students \n");
		printf("4 : Delete All Students\n");
		printf("6 : get_NthStudentFromEnd \n");
		printf("7 : Reverse Records \n");
		printf("8 : Exit System\n");

		printf("========================================\n");

		gets(temp_option);
		switch(atoi(temp_option)){

		case 1 :
			add_Student();
			break;
		case 2 :
			delete_Students();
			break;
		case 3 :
			view_Students();
			break;
		case 4 :
			delete_AllStudents();
			break;
		case 5 :
			get_NthStudentFromEnd();
			break;
		case 6 :
			get_MiddleNode();
			break;
		case 7 :
			 reverse_Records();
			break;
		case 8 :
			Exit();
			break;
		default :
			printf("Wrong option\n");

			printf("========================================\n");
			break;
		}
	}

	return 0;
}




// function to score information about the new student
void create_NewRecord(struct Sstudent* Newstudent){
	unsigned char temp_text[20];
	printf("Enter Student Name : ");
	gets(Newstudent->student.Name);

	printf("\nEnter Student ID : ");
	gets(temp_text);
	Newstudent->student.ID = atoi(temp_text);

	printf("\nEnter Student Height : ");
	gets(temp_text);
	Newstudent->student.Height = atof(temp_text);

}


//function to add new student to the system
void add_Student(){
	struct Sstudent* Newstudent = (struct Sstudent*) malloc(sizeof(struct
			Sstudent*));  ;

	create_NewRecord(Newstudent);

	//if list is empty
	if(Headstudent == NULL){

		//make newstudent point to null
		Newstudent->Nextstudent = Headstudent;

		//make head point to new student
		Headstudent = Newstudent;
	}

	//Here list has nodes
	Currentstudent = Headstudent;
	// loop with current student until reach the end of list
	while(Currentstudent->Nextstudent != NULL)
	{
		Currentstudent = Currentstudent->Nextstudent;
	}
	Currentstudent->Nextstudent = Newstudent;
	Newstudent ->Nextstudent = NULL;	//insert new student at last of the list

}


// function to view students information
void view_Students(){

	int count = 0;
	//check is the list is empty
	if(Headstudent == NULL){
		printf("=======Empty List========\n ");
		return ;
	}

	//Here list has records
	Currentstudent = Headstudent;

	while(Currentstudent != NULL){
		printf("Student Name is :%s",Currentstudent->student.Name);
		printf("\nStudent ID is :%d",Currentstudent->student.ID);
		printf("\nStudent Name is :%f",Currentstudent->student.Height);
		Currentstudent = Currentstudent->Nextstudent;
		count++;
	}

}


//function to delete students
void delete_Students(){
	unsigned char temp_text[40];
	unsigned int selected_id;
	struct Sstudent* Deletestudent = NULL;

		printf("Please Enter the selected id to delete\n");
		gets(temp_text);
		selected_id = atoi(temp_text);

		//check is the list is empty
		if(Headstudent == NULL){
			printf("=======Empty List========\n ");
			return ;
		//check if the first student in the list
		if(Headstudent->student.ID == selected_id){
			Deletestudent = Headstudent;
			Headstudent = Headstudent->Nextstudent;	//move head to next
			free(Deletestudent);
			return ;
		}
		Currentstudent = Headstudent->Nextstudent;
		Prevstudent = Headstudent;
		while(Currentstudent != NULL)
		{
			if(Currentstudent->student.ID == selected_id)
			{
				//element found
				Deletestudent = Currentstudent;
				Prevstudent->Nextstudent = Currentstudent->Nextstudent;
				free(Deletestudent);
				return;

				Prevstudent = Currentstudent;
				Currentstudent = Currentstudent->Nextstudent;
				//in case the id  not found in the linked list
				if(Deletestudent == NULL)
				{
					printf("%d not found in the List.",selected_id);
				}
			}
		}
	}
}




//function to delete all students
void delete_AllStudents(){

	Currentstudent = Headstudent;
	if(Headstudent == NULL){
		printf("=======Empty List========\n ");

		while(Currentstudent){
			struct Sstudent* Tempstudent =Currentstudent;
			Currentstudent= Currentstudent->Nextstudent;
			free(Tempstudent);

		}
		Headstudent = NULL;
	}


}


//function to exit system
void Exit(){
	Flag = 0;
}

//get nth node in linked list from the end
void get_NthStudentFromEnd()
{
	int n,count=0;
	struct Sstudent* MainStudent=Headstudent;
	struct Sstudent* RefStudent=Headstudent;
	printf("Enter the index from the end of the list: ");
	scanf("%d",&n);
	if(RefStudent)
	{
		//loop until reach to the end
		while(RefStudent)
		{
			if(count == n)//the main pointer start to move
			{
				RefStudent=RefStudent->Nextstudent;
				MainStudent=MainStudent->Nextstudent;
			}
			else//ref pointer move until reach to the end
			{
				RefStudent=RefStudent->Nextstudent;
				count++;
			}
		}
		//view the data of this node
		printf("\n\t Student ID: %d",MainStudent->student.ID);
		printf("\n\t Student Full Name: %s",MainStudent->student.Name);
		printf("\n\t Student Height: %f",MainStudent->student.Height);
		printf("\n-------------------------------------------------\n");
	}
	else
	{
		printf("The list is Empty!");
	}
}


//get the middle node in the list
void get_MiddleNode()
{
	struct Sstudent* SlowStudent=Headstudent;
	struct Sstudent* FastStudent=Headstudent;
	//check the list is empty
	if(FastStudent)
	{
		//loop until reach to end of list
		while(FastStudent)
		{
			//check that the next of fast pointer is null
			if(FastStudent->Nextstudent != NULL)
			{
				FastStudent=FastStudent->Nextstudent->Nextstudent;
				SlowStudent=SlowStudent->Nextstudent;
			}
			else
			{
				FastStudent=FastStudent->Nextstudent;
			}
		}
		//view the data of this node
		printf("\n\t Student ID: %d",SlowStudent->student.ID);
		printf("\n\t Student Full Name: %s",SlowStudent->student.Name);
		printf("\n\t Student Height: %f",SlowStudent->student.Height);
		printf("\n-------------------------------------------------\n");
	}
	else
	{
		printf("The list is Empty!");
	}
}

//reverse the list
void reverse_Records()
{
	struct Sstudent* Currentstudent=Headstudent->Nextstudent;
	struct Sstudent* Prevstudent=Headstudent;
	struct Sstudent* Nextstudent=NULL;
	//check the list is empty
	if(Headstudent)
	{
		while(Currentstudent)
		{
			Nextstudent=Currentstudent->Nextstudent;
			Currentstudent->Nextstudent = Prevstudent;
			Prevstudent = Currentstudent;
			Currentstudent =Nextstudent;
		}
		Headstudent->Nextstudent = NULL;
		Headstudent =Prevstudent;
	}
	else
	{
		printf("The list is Empty!");
	}
}
