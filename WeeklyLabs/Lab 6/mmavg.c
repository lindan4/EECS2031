/***********************************
* EECS 2031 - Lab 6		   
* Filename: mmavg.c	  	
* Author: Last name, first name	    
* Email: Your preferred email address	 	
* Login ID: Your EECS login ID	
************************************/


#include <stdio.h>
#include <stdlib.h>


  /*****  YOU MAY ADD YOUR OWN FUNCTION(S) HERE.  *****/

int convertToInteger(char *t)
{
	int j;
	int digitHolder = 0;
	int sumHolder = 0;
	
	const int TEN = 10;
	
	for (j = 0; *(t + j) != '\0'; j = j + 1)
	{
		if (*(t + j) == '-')
		{
			continue;
		}
		if (*(t + j) >= '0' && *(t + j) <= '9')
		{
			digitHolder = *(t + j) - '0';
			sumHolder = (sumHolder * TEN) + digitHolder;
		}
	}
	return (*t == '-') ? -sumHolder : sumHolder;
}


/* Function main()
   Input: a set of integers as command-line arguments.
   Output: the maximum, minimum and average of the above set displayed on the standard output.
 */

main( int argc, char *argv[] )
{
  int max, min;
  float avg;

  /*****************************************/
  /***** ADD YOUR CODE BELOW THIS LINE *****/

  max = min = 0;
  int i, limit;
  const int STANDARD_LIM = 101;
  char *numCharHolder;
  
  int theNumber = 0;
  int initialMaxMinSignal = 0;
  int sumHolder = 0;
  int numIntegers = 0;
  
  limit = (argc < STANDARD_LIM) ? argc : STANDARD_LIM;
  
  if (limit == 1)
  {
  	  printf("Usage: mmavg int 1 int 2 int 3 ...\n");
  	  return 0;
  }
  else
  {
  	  for (i = 1; i < limit; i = i + 1)
  	  {
  	  	  numCharHolder = *(argv + i);
  	  	
  	  	  theNumber = convertToInteger(numCharHolder);
  	  	  sumHolder = sumHolder + theNumber;
  	  	  numIntegers++;
  	  		  
  	  	  if (!initialMaxMinSignal)
  	  	  {
  	  	  	  max = min = theNumber;
  	  	  	  initialMaxMinSignal = 1;
 		  }
    		  if (theNumber > max)
    		  {
    		  	  max = theNumber;
    		  }
  	  	  
    		  if (theNumber < min)
    		  {
    		  	  min = theNumber;
    		  }
  	  	  
  	}
  	
  	//printf("Sum holder: %d Number of integers: %d\n", sumHolder, numIntegers);

  	avg = (float) sumHolder / (float) numIntegers;
  }
  
  



  /***** ADD YOUR CODE ABOVE THIS LINE *****/
  /*****************************************/

  /**** DO NOT ADD OR CHANGE ANYTHING BELOW THIS LINE ****/

  printf( "%d %d %.2f\n", max, min, avg );
}

