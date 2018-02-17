/***************************************
* EECS2031 – Lab 2                     *
* File name: lab2c.c                   *
* Author: Last name, first name        *
* Email: Your email address            *
* Login ID: Your EECS login ID         *
****************************************/

#include <stdio.h>

#define MAX_SIZE 100

void main() {

    char my_strg[ MAX_SIZE ];
    int my_int;

    /********** Fill in your code here. **********/
	int len, i, sign;
	char c;

    /* Read in the input string */
	len = 0;
	c = getchar();
	while( c != '\n' ) {
		my_strg[ len++ ] = c;
		c = getchar();
	} 
	my_strg[ len ] = '\0';

	/* Convert the string to an integer */
	my_int = 0;
	i = 0;
	sign = 1;
	if ( my_strg[ i ] == '+' )
		i++;
	else if ( my_strg[ i ] == '-' ){
		sign = -1;
		i++;
	}
  	while ( my_strg[ i ] != '\0' ){
    	my_int = my_int * 10 + ( my_strg[ i ] - '0' );
    	i++;
  	}
  	my_int = my_int * sign;

   	printf( "%10d\n", my_int );  /* output the integer */
}
