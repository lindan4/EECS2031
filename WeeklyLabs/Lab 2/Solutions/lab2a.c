/***************************************
* EECS2031 – Lab 2                     *
* File name: lab2a.c                   *
* Author: Last name, first name        *
* Email: Your email address            *
* Login ID: Your EECS login ID         *
****************************************/

#include <stdio.h>

void main() {
	int digits = 0, sum = 0;
	char c;
	
	printf( "Enter a line of characters>" );
	c = getchar();
	while( c != '\n' ) {
		if ( c >= '0' && c <='9' ) {
		   digits++;
		   sum += c - '0'; 
		}
		c = getchar();
	} 
	printf( "%d\t%d\n", digits, sum );
}