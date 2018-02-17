/***************************************
* EECS2031 – Lab 1                      *
* Filename: lab1a.c                    *
* Author: Last name, first name        *
* Email: Your email address            *
* Login ID: Your EECS login ID         *
****************************************/

#include <stdio.h>

void main() {
	float inch, cm;
	
	printf( "Enter the measurement in inches > " );
	scanf( "%f", &inch );
	while( inch != 0 ) {
		cm = inch * 2.54;
		printf( "%.2f cm\n", cm );
		printf( "Enter the measurement in inches > " );
		scanf( "%f", &inch );
	} 
}

