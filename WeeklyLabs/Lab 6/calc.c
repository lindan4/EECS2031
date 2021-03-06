/***********************************
* EECS 2031 - Lab 6		   
* Filename: calc.c	  	
* Author: Last name, first name	    
* Email: Your preferred email address	 	
* Login ID: Your EECS login ID	
************************************/


#include <stdio.h>
#include <stdlib.h>


  /*****  YOU MAY ADD YOUR OWN FUNCTION(S) HERE.  *****/

int isNumber(char *s)
{
	while (*s != '\0')
	{
		if (*s > '9' || *s < '0')
		{
			return 0;
		}
		s++;
	}
	return 1;
}

int isOperator(char *t)
{
	while (*t != '\0')
	{
		if (*t != '+' && *t != '-' && *t != 'x' && *t != '/' && *t != '%')
		{
			printf("%c\n", *t);
			return 0;
		}
		t++;
	}
	return 1;
}
	


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
		digitHolder = *(t + j) - '0';
		sumHolder = (sumHolder * TEN) + digitHolder;
	}
	return (*t == '-') ? -sumHolder : sumHolder;
}




/* Implement a simple calculator. 
   Input: two operands and one operator as command-line arguments.
   Output: the result displayed on the standard output. 
 */

int main( int argc, char *argv[] )
{
  int result = 0;  /* stores the result of the arithmetic operation */


  /*****************************************/
  /***** ADD YOUR CODE BELOW THIS LINE *****/
  
  const int FIVE = 5;
  char *a, opHolder;
  int i, checkForNumber, checkForOperand;
  
  int sumHolder = 0;
  
  int numberPos, opPos, operandFound, operatorAfterOperand = 0;
  
  
   //printf("argc count %d\n", argc);

   
  int j, k;
  if (argc == 4)
  {
  	    for (i = 1; i < argc; i = i + 1)
  	    {
  	  	a = *(argv + i);
  	  	
  	  	if (i == 1)
  	  	{
  	  		checkForNumber = isNumber(a);
  	  		if (checkForNumber)
  	  		{
  	  			j = convertToInteger(a);
  	  		}
  	  		else
  	  		{
  	  			printf("Usage: calc [operand_1] [operator] [operand_2]\n");
  	  		  	return 0;

  	  		}
  	  	}
  	  	else if (i == 3)
  	  	{
  	  		checkForNumber = isNumber(a);
  	  		if (checkForNumber)
  	  		{
  	  			k = convertToInteger(a);
  	  		}
  	  		else
  	  		{
  	  			printf("Usage: calc [operand_1] [operator] [operand_2]\n");
  	  			return 0;
  	  		}
  	  		
  	  	}
  	  	else 
  	  	{
  	  		checkForOperand = isOperator(a);
  	  		if (checkForOperand)
  	  		{
  	  			opHolder = *a;
  	  		}
  	  		else
  	  		{
  	  			printf("Usage: calc [operand_1] [operator] [operand_2]\n");
  	  			return 0;
  	  		}
  	  	}
  	  	//printf("Argument %d: %s\n", i, a);
  	    }
  	    
  	    if (opHolder == '+')
  	    {
  	    	    result = j + k;
  	    }
  	    else if (opHolder == '-')
  	    {
  	    	    result = j - k;
  	    }
  	    else if (opHolder == 'x')
  	    {
  	    	    result = j * k;
  	    }
  	    else if (opHolder == '/')
  	    {
  	    	    result = j / k;
  	    }
  	    else if (opHolder == '%')
  	    {
  	    	    result = j % k;
  	    }
  	    else
  	    {
  	    	    printf("Usage: calc [operand_1] [operator] [operand_2]\n");
  	    	    return 0;
  	    }
  }
  else if (argc == 2)
  {
  	  checkForNumber = isNumber(*(argv + 1));
  	  if (checkForNumber)
  	  {
  	  	  result = convertToInteger(*(argv + 1));
  	  }
  }
  else  	  
  {
  	  printf("Usage: calc [operand_1] [operator] [operand_2]\n");
  	  return 0;
  }





  /***** ADD YOUR CODE ABOVE THIS LINE *****/
  /*****************************************/

  /**** DO NOT ADD OR CHANGE ANYTHING BELOW THIS LINE ****/

  printf( "%d\n", result );
  
  return 0;
}

