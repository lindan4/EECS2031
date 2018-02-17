

#include <stdio.h>

int main()
{
	int c;
	int sumOfNumbers, numberCount = 0;
	
	printf("Enter a line of characters>");
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		if (c >= '0' && c <= '9')
		{
			++numberCount;
			sumOfNumbers = sumOfNumbers + (c - '0');
		}
	}
	printf("\n%d\t%d\n", numberCount, sumOfNumbers);
	
	
	return 0;
}
