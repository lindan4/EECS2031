#include <stdio.h>

#define MAX_SIZE 100
#define EIGHT 8


int octalToDec(char s[], int size);
int toPower(int a, int b);

main() 
{

   char my_strg[MAX_SIZE];   /* to store the octal number in the form of an array of char */
   int my_int;

   /********** Fill in your code here. **********/
   
   int c, position, nonOctalSignal;
   
   putchar('\n');
   position = 0;
   nonOctalSignal = 0;
   while (((c = getchar()) != EOF) && (c != '\n'))
   {
   	  
   	   if ((c >= '0' && c <= '7') || (c == '-'))
   	   {
   	   	   my_strg[position] = c;
   	   	   position = position + 1;
   	   }
   	   else
   	   {
   	   	   nonOctalSignal = 1; 	   	   
   	   }
   }
      
   my_strg[position] = '\0';
   
   if (nonOctalSignal == 1)
   {
   	printf("\nError: not an octal number\n");
   }
   else
   {
   	   my_int = octalToDec(my_strg, position);
   
   	   if (my_strg[0] == '-')
   	   {
   	   	   my_int = ~my_int + 1;
   	   }
   
   //printf("%s", my_strg);
   	   putchar('\n');
   	   printf( "%10d\n", my_int );
   }
   
     /* output the decimal integer */
}

int octalToDec(char s[], int size)
{
	int digit, hold;
	char charAsDigit;
		
	hold = 0;
	
	int pos;
	
	
	if (s[0] = '-')
	{
		s[0] = '0';
	}
	
	for (pos = 0; s[pos] != '\0'; pos = pos + 1)
	{
		digit = s[pos] - '0';
		hold = hold + (digit * toPower(EIGHT, size - 1 -pos));
	}
	
	return hold;


	
}

int toPower(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else if (b < 0)
	{
		return (1 / a) * toPower(a, b + 1);
	}
	else
	{
		return a * toPower(a, b - 1);
	}
}

