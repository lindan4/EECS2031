/***********************************
* EECS 2031 - Lab 8
* Filename: slen.c
* Author: Thillanayagam, Lindan
* Email: lindan4@my.yorku.ca	 	
* Login ID: lindan4	
************************************/


#include <stdio.h>
#include <stdlib.h>


int getLength(char *s)
{
	int count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return count;
}



/* Allocate a 2D array with the number of rows being "num_of_str", 
   each row having "str_len" columns. 
   If an error occurs, display an error message and return NULL.
*/
char** alloc2D( int num_of_str, int str_len )
{

   char **st;

   /* ===========  ADD YOUR CODE BELOW THIS LINE  =========== */
   
   int i;
   st = (char **) malloc(num_of_str * sizeof(char *));
   
   if (st == NULL)
   {
   	   printf("Insufficient memory.\n");
   	   return NULL;
   }
   else
   {
   	   for (i = 0; i < num_of_str; i = i + 1)
   	   {
   	   	   *(st + i) = (char *) malloc(str_len * sizeof(char));
   	   	   //printf("%d\n", i);
   	   	   if (*(st + i) == NULL)
   	   	   {
   	   	   	   printf("Insufficient memory.\n");
   	   	   	   return NULL;
   	   	   }
   	   }
   }
   
   /* ===========  ADD YOUR CODE ABOVE THIS LINE  =========== */
   
   return st;
   
}  /* alloc2D */


/* For each string, compute the string length by counting the 
   characters one by one.  Then display on the standard output
   the string, followed by a tab, then the length of the string.
*/
void str_lengths( char **st, int num_of_str )
{

   /* ===========  ADD YOUR CODE HERE  =========== */
   
   /* Do not use any C library function here, except printf. */
   
   int j, length;
   char *lineString;
   //printf("num of string: %d\n", num_of_str);
   for (j = 0; j < num_of_str; j = j + 1)
   {
   	   lineString = (char *) *(st + j);
   	   length = getLength(lineString);
   	   printf("%s\t%d\n", lineString, length);
   }
   
}  /* str_lengths */
