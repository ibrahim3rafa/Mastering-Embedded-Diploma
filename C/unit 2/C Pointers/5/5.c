/*
 * 5.c
 *
 *  Created on: May 4, 2023
 *      Author: ARAFA
 */

#include<stdio.h>
struct employee{
	char*empname;
	int empid;
}emp1,emp2;
int main(){

	struct employee emp1 = {"John",1001};
	struct employee emp2 = {"Alex",1002};

	struct employee (*arr[]) = {&emp1,&emp2};
	struct employee(*(*ptr)[2]) =&arr;

	printf("Empoloyee name is %s \n",(**(*ptr+1)).empname);
	printf("Emp ID is %d \n",(*(*ptr+1))->empid);
	return 0;
}
