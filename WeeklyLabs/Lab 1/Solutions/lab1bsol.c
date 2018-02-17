/***************************************
* EECS2031 – Lab 1                     *
* Filename: lab1b.c                    *
* Author: Last name, first name        *
* Email: Your email address            *
* Login ID: Your EECS login ID         *
****************************************/

#include <stdio.h>

void main() {
	int blanks = 0;
	char c;
	
	printf( "Enter a line of characters > " );
	c = getchar();
	while( c != '\n' ) {
		if ( c == ' ' )
			blanks++;
		c = getchar();
	} 
	printf( "%d\n", blanks );
}

