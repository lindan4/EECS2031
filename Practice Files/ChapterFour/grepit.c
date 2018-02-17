#include <stdio.h>
#include <ctype.h>



#define MAX_SIZE 1000

int getLength(char *s);
int strindex(char s[], char t[]);
int strrindex(char s[], char t[]);


int main(void)
{
	char listLines[MAX_SIZE];
	char patternSearch[MAX_SIZE];
	
	int c, d, position, patternResult, patternResultRight;
	position = 0;
	
	printf("Enter sentence(s):\n\n");
	
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		listLines[position] = c;
		position++;
	}
	listLines[position] = '\0';
	
	printf("\nEnter pattern to look for: ");
	position = 0;
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		patternSearch[position] = d;
		position++;
	}
	
	patternSearch[position] = '\0';
	position = 0;
	
	patternResult = strindex(listLines, patternSearch);
	patternResultRight = strrindex(listLines, patternSearch);
	
	printf("\nDoes the pattern exist? %d %s\n", patternResult, (patternResult != -1) ? "Yes" : "No");
	printf("Does ths pattern exist (right occurence)? %d %s\n", patternResultRight, (patternResultRight != -1) ? "Yes" : "No");
	
	
	return 0;
}

int getLength(char *s)
{
	int counter = 0;
	
	while (*s != '\0')
	{
		s++;
		counter++;
	}
	return counter;
}

//Look over definition of function
int strindex(char s[], char t[])
{
	int i, j, k;
	
	for (i = 0; s[i] != '\0'; i = i + 1)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
		{
			//printf("%c %c\n", s[j], t[k]);
		}
		if (k > 0 && t[k] == '\0')
		{
			return i;
		}
	}
	
	return -1;
}

int strrindex(char s[], char t[])
{
	int i, j, k;
	
	int rightStart = getLength(s);
	
	
	for (i = rightStart - 1; i >= 0; i = i - 1)
	{
		printf("%d\n", i);

		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
		{
			printf("%c %c\n", s[j], t[k]);
		}
		if (k > 0 && t[k] == '\0')
		{
			printf("Well it's going here %d\n", i);
			return i;
		}
	}
	return -1;
	
}