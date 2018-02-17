

#include <stdio.h>
#include <math.h>


int main()
{
	//Issue: printing out incorrect numbers
	//Fix: Recall that c is treated as a character here when getchar is invoked
	
	//Issue: Negative numbers
	//Solution: append it to beginning if - character exists
	
	#define MAX_SIZE 100
	const int TEN = 10;
	const int ONE = 1;
	
	
	long int c;
	long int digitPos, digitHolder, numberPower, numberHolder = 0;
	long int my_strg[MAX_SIZE];
	
	char positiveOrNegative = ' ';
	
	
	printf("\n");
	
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		if (c == '-')
		{
			positiveOrNegative = c;
		}
		else
		{
			my_strg[digitPos] = c - '0';
			digitPos = digitPos + ONE;
		}
		
	}
	
	for (int i = 0; i < digitPos; i = i + 1)
	{
		long int toPower = pow(TEN, digitPos - 1 - i);
		numberHolder = numberHolder + my_strg[i] * toPower;
	}
	
	if (positiveOrNegative == '-')
	{
		numberHolder = ~numberHolder + 1;
		
	}
	
	printf("\n%10d\n", numberHolder);
}

