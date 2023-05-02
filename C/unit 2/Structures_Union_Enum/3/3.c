/*
 * 3.c
 *
 *  Created on: May 2, 2023
 *      Author: ARAFA
 */

/*
 * 3.c
 *
 *  Created on: May 2, 2023
 *      Author: ARAFA
 */

#include<stdio.h>
typedef struct Scomplex{
	float real ;
	float imag;
}complex;
complex sum(complex n1,complex n2);

int main(){

	complex n1,n2,res;
	printf("For first complex number \n");
	printf("Enter real and imag respectivly:");
	fflush(stdout);
	scanf("%f %f",&n1.real,&n1.imag);

	printf("For second complex number \n");
	printf("Enter real and imag respectivly:");
	fflush(stdout);
	scanf("%f %f",&n2.real,&n2.imag);

	res = sum(n1,n2);

	printf("sum = %.1f+%.1fi",res.real, res.imag);

	return 0;
}
complex sum(complex n1,complex n2){
	complex  temp;
	temp.real = n1.real + n2.real;
	temp.imag = n1.imag + n2.imag;
	return (temp);
}

