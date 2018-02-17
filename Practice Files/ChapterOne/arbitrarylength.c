

#include <stdio.h>
#include <stdlib.h>


int getLineLength(char s[]);
void copy(char to[], char from[]);
void changeArraySize(char initial[]);

main()
{
	//Task: create program that will print out longest line of arbitrary size
	
	//Avoid brackets
	#define INITIAL_MAX_LINE 1000
	
	char inputLine[INITIAL_MAX_LINE];
	char longestLine[INITIAL_MAX_LINE];
	
	int input;
	int len, max;
	
	max = 0;
	printf("Input text: ");
	
	while ((len = getLineLength(inputLine)) > 0)
	{
		if (len > max)
		{
			copy(longestLine, inputLine);
			max = len;

		}
		if (max > 0)
		{
			printf("\"%s\" has %d characters\n", longestLine, max);
			printf("Input text: ");
		}
	}
	return 0;
	
}

int getLineLength(char s[])
{
	int c, counter;
	int j;

	counter = 0;
	for (j = 0; (c = getchar())!= EOF && c != '\n'; j = j + 1)
	{
		s[j] = c;
		counter = counter + 1;
		
	}
	
	if (c == '\n')
	{
		//s[j] = c;
		j  = j + 1;
	}
	
	s[j] = '\0';
	return counter;
}

void copy(char to[], char from[])
{
	int i = 0;
	
	while ((to[i] = from[i]) != '\0')
	{
		i = i + 1;
	}
	
}
