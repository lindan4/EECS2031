

#include <stdio.h>

int main()
{
	#define MAX 10000
	int c, lim;
	char s[MAX];
	printf("Input line:\n");
	
	int counter = 0;
	
	for (c = getchar(); c != '\n'; c = getchar())
	{
		if (c == EOF)
		{
			c = '\n';
		}
		else
		{
			s[counter] = c;
			putchar(c);
			++counter;
		}
	}
	s[counter + 1] = '\0';
	
	
	return 0;
}
