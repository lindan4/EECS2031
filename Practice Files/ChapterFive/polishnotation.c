#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7000


int isNumber(char *s);
int isArithSign(char *s);
int convertToNumber(char *s);
//char *argv[] is an array of pointers

//Incomplete
int main(int argc, char *argv[])
{
	int i;
	int decPos = 0; 
	int arthPos = 0;
	int decimals[MAX_SIZE];
	char arith[MAX_SIZE];
	int convertedNumber;
	
	//Transfer input strings from the 'argv' pointer array to the 'takeInput' array
	for (i = 1; i < argc; i = i + 1)
	{
		*++argv;
		
		if (isNumber(*argv))
		{
			convertedNumber = convertToNumber(*argv);
			//printf("sum %d\n", convertedNumber);
			decimals[decPos] = convertedNumber;
			decPos++;
			//*(takeInput + i - 1) = *argv;
		}
		else
		{
			//printf("Arith sign: %d\n", isArithSign(*argv));
			if (isArithSign(*argv))
			{
				arith[arthPos] = *argv[0];
				arthPos++;	
			}
		}
		//printf("Is number %d\n", isNumber(*argv));
	}
	
	decPos--;
	arith[arthPos] = '\0';
	
	int a, b;
	int outcomeHolder = 0;
	int k;
	char holdOp;
	for (k = 0; k < arthPos; k = k + 1)
	{
		holdOp = arith[k];
		a = decimals[decPos];
		decPos--;
		b = decimals[decPos];
		decPos--;
		
		if (holdOp == '+')
		{
			outcomeHolder = outcomeHolder + (a + b);
		}
		if (holdOp == '-')
		{
			outcomeHolder = outcomeHolder + (a - b);
		}
		if (holdOp == '*')
		{
			outcomeHolder = outcomeHolder + (a * b);
		}
		if (holdOp == '/')
		{
			outcomeHolder = outcomeHolder + (a / b);
		}
		if (holdOp == '%')
		{
			outcomeHolder = outcomeHolder + (a % b);
		}
	}
	printf("Sum: %d", outcomeHolder);
	
	
	return 0;
}

int isNumber(char *s)
{
	//printf("Char %c\n", *s);
	while (*s != '\0')
	{
		if (!(*s >= '0' && *s <= '9'))
		{
			return 0;
		}
		s++;
	}
	return 1;
}

int isArithSign(char *s)
{
	while (*s != '\0')
	{
		
		//printf("Hehe: %c\n", *s);
		if (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '%')
		{
			return 1;
		}
		s++;
	}
	return 0;
}

int convertToNumber(char *s)
{
	const int TEN = 10;
	
	int i, digitHolder, sumHolder;
	sumHolder = 0;
	for (i = 0; *(s + i) != '\0'; i = i + 1)
	{
		digitHolder = *(s + i) - '0';
		sumHolder = (sumHolder * TEN) + digitHolder;
	}
	//printf("sum %d", sumHolder);
	return sumHolder;
}


