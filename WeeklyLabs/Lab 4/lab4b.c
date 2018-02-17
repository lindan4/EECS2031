/***********************************
* EECS2031 - Lab 4		   
* Filename: lab4b.c		  	
* Author: Last name, first name	    
* Email: Your preferred email address	 	
* Login ID: Your login ID    		
************************************/

#include <stdio.h>

#define MAX_SIZE 100
#define TEN 10

double convertArrayToFloat(char s[]);
int getArrayLength(char t[]);

main() {

   char my_strg[MAX_SIZE];
   double my_number = 0.0;
   

   /********** Add your code below this line **********/
   int c, position, singleDecimalFound;
   
   putchar('\n');
   position = 0;
   singleDecimalFound = 0;
   
   while (((c = getchar()) != EOF) && (c != '\n'))
   {
   	   if (position == 0 && c == '-')
   	   {
   	   	   my_strg[position] = c;
   	   	   position = position + 1;
   	   }
   	   else
   	   {
   	   	   if (c >= '0' && c <= '9')
   	   	   {
   	   	   	   my_strg[position] = c;
   	   	   	   position = position + 1;
   	   	   }
   	   	   else
   	   	   {
   	   	   	   if (c == '.' && singleDecimalFound == 0)
   	   	   	   {
   	   	   	   	   my_strg[position] = c;
   	   	   	   	   position = position + 1;
   	   	   	   	   singleDecimalFound = 1;
   	   	   	   }
   	   	   	   else
   	   	   	   {
   	   	   	   	   printf("\nInvalid floating point number\n");
   	   	   	   	   return 1;
   	   	   	   }
   	   	   }
   	   }
   }
   my_strg[position] = '\0';
   
   my_number = convertArrayToFloat(my_strg);
   putchar('\n');

   //printf("%s\n", my_strg);
   /********** Add your code above this line **********/
   

   printf( "%.6f\n", my_number );
}

//How about negative numbers?
//
double convertArrayToFloat(char s[])
{	
	//1. Check for negative
	//2. Add number: 28.25 = 20 + 8 + 0.2 + 0.05
	
	int length = getArrayLength(s);
	int i, charHolder;
	int visibleDecimal = 0;
	double sumHolder = 0;
	double divideBy = (double) TEN;
	
	
	for (i = 0; i < length; i = i + 1)
	{
		charHolder = s[i];
		if (charHolder != '-')
		{
			if (charHolder == '.' && visibleDecimal == 0)
			{
				visibleDecimal = 1;
				continue;
			}
		
			if (!visibleDecimal)
			{
				charHolder = charHolder - '0';
				sumHolder = (sumHolder * TEN) + (double) charHolder;
			}
			else
			{
				charHolder = charHolder - '0';
				sumHolder = sumHolder + ((double) charHolder/ divideBy);
				divideBy = divideBy * (double) TEN;
			}
		}
		
	}
	
	return (s[0] == '-') ? -sumHolder : sumHolder;
}

int getArrayLength(char t[])
{
	int count = 0;
	while (t[count] != '\0')
	{
		count++;
	}
	
	return count;
}
