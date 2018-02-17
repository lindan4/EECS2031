/***************************************
* EECS2031 – Lab 3                     *
* File name: lab3b.c                   *
* Author: Last name, first name        *
* Email: Your email address            *
* Login ID: Your EECS login ID         *
****************************************/

#include <stdio.h>
#define MAX_SIZE 100

void main() 
{
	char my_strg[ MAX_SIZE ];
	int len = 0, my_int = 0, pos = 0, sign = 1, err = 0; 
	char c;
	
	/* Input an octal as a string */
	c = getchar();
	while( c != '\n' ) {
		my_strg[ len++ ] = c;
		c = getchar();
	} 
	my_strg[ len ] = '\0';

	/* Check for the minus sign (negative number) */
    if( my_strg[ 0 ] == '-' ) {
    	sign = -1;
    	pos = 1;  /* move to the next char */
    }
    else if( my_strg[ 0 ] == '+' )
    	pos = 1;  /* move to the next char */
    
    /* Convert the octal to a decimal number */
  	while ( my_strg[ pos ] != '\0' ) {
  	  if ( my_strg[ pos ] >= '0' && my_strg[ pos ] <= '7' ) {
    	my_int = my_int * 8 + ( my_strg[ pos ] - '0' );
    	pos++;
      }
      else { /* encounter invalid input character */	
        err = 1;
        break;
      }
  	}
  	
  	if ( err )
  		printf( "Error: not an octal number\n" );
  	else	
		printf( "%10d\n", my_int * sign );
}

