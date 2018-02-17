/***********************************
* EECS2031 - Lab 4		   
* Filename: lab4a.c		  	
* Author: Last name, first name	    
* Email: Your preferred email address	 	
* Login ID: Your login ID    		
************************************/

#include <stdio.h>

#define MAX_SIZE 500

void myStrInput ( char *s );
int myStrCmp( char *s1, char *s2 );
int getLength(char *line);

main() 
{
   char strg1[ MAX_SIZE ], strg2[ MAX_SIZE ];

   /* Input strings strg1 and strg2. */
   /* Assume that the length of each input string is less than 100 characters. */

   myStrInput(strg1);
   myStrInput(strg2);
   printf( "%d\n", myStrCmp( strg1, strg2 ));
}


/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/


/* Function myStrInput
   Input: an array of char pointed to by pointer s.
   Output: the same array that stores the user's input string.
   Note: The length of each input string is less than the array size. 
   So no error checking for the string length is required. 
   Do not modify the function definition.
 */

void myStrInput ( char *s )
{
	int c, position;
	position = 0;
	
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		*(s + position) = c;
		position = position + 1;
	}
	*(s + position) = '\0';

   /* Add your code here. */
   /* Do not use array indexing. */
   /* You may define additional variables, except arrays. */
   /* Do not use any C library functions, except getchar(). */
	
}



/* Function myStrCmp
   Input: two strings pointed to by pointers s1 and s2.
   Output: returns the first position (array index) where the two strings differ. 
   Special cases:
   1. Two strings are equal: returns -1.
   2. One string is a substring of the other (e.g., "CSE2031" and "CSE2031E3.0"):
	returns the length of the shorter string.
   Do not modify the function definition.
 */

int myStrCmp( char *s1, char *s2 )
{
	int positionCount = 0;
	while (*s1 == *s2)
	{
		if (*s1 == '\0' && *s2 == '\0')
		{
			return -1;
		}
		else if (*s1 == '\0' && *s2 != '\0')
		{
			return getLength(s2);
			
		}
		else if (*s1 != '\0' && *s2 == '\0')
		{
			return getLength(s1);
		}
		else
		{
			s1++;
			s2++;
			positionCount = positionCount + 1;
		}
	}
	
	return positionCount;

   /* Add your code here. */
   /* Do not use array indexing. */
   /* You may define additional variables, except arrays. */
   /* Do not use any C library functions. */

}

int getLength(char *line)
{
	int count = 0;
	while (*line != '\0')
	{
		count = count + 1;
		line++;
	}
	return count;
}

