

#include <stdio.h>

#define MAX_CHARACTERS 10000
#define ONE 1

int firstOccurenceOfChar(char s[], char lookFor);

int main()
{
	int c, d, position, singleCharacter, count;
	
	
	char lineOfCharac[MAX_CHARACTERS];
	
	printf("\nEnter a line>");
	position = 0;
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		//putchar(c);
		lineOfCharac[position] = c;
		position = position + 1;
	}
	lineOfCharac[position] = '\0';
	//printf("%d", position);
	position = position + 1;
	
	printf("\nEnter the character to find>");
	singleCharacter = 1;
	
	while (((d = getchar()) != EOF) && (d != '\n') && (count < ONE))
	{
		singleCharacter = d;
		count = count + 1;
	}
	
	int firstPosition = firstOccurenceOfChar(lineOfCharac, singleCharacter);
	
	printf("\nThe character %c first occurs in position %d\n", singleCharacter, firstPosition);

	
	return 0;
}


int firstOccurenceOfChar(char s[], char lookFor[])
{
	int j, locationValue;
	
	
	char firstOccur = ' ';
	
	for (j = 0; s[j] != '\0'; j = j + 1)
	{
		if (s[j] == lookFor)
		{
			firstOccur = s[j];
			break;
		}
	}
	
	if (firstOccur != ' ')
	{
		locationValue = j;
	}
	else
	{
		locationValue = -1;
	}
	
	return locationValue;
}




