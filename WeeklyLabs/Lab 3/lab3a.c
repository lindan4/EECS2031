#include <stdio.h>

#define MAX_SIZE 100

void reverse(char s[], int size);

main() 
{

   char my_strg[MAX_SIZE];

   int c, position;
   position = 0;
   
   putchar('\n');
   
   while (((c = getchar()) != EOF) && (c != '\n'))
   {
   	   my_strg[position] = c;
   	   position = position + 1;
   }
   
   my_strg[position] = '0';
   reverse(my_strg, position);
   

   putchar('\n');
   printf( "%s\n", my_strg );  /* output the reversed string */
}

void reverse(char s[], int size)
{
	int i, rightPosition;
	char temp;
	
	rightPosition = size - 1;
	
	//array has three positions
	if (size % 2 == 0)
	{
		i = 0;
		while (i < rightPosition)
		{
			temp = s[i];
			s[i] = s[rightPosition];
			s[rightPosition] = temp;
			
			i = i + 1;
			rightPosition = rightPosition - 1;
		}
	}
	else
	{
		i = 0;
		while (i != rightPosition)
		{
			temp = s[i];
			s[i] = s[rightPosition];
			s[rightPosition] = temp;
			
			i = i + 1;
			rightPosition = rightPosition - 1;
			
		}
	}
	
	s[size] = '\0';
}
