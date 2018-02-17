

#include <stdio.h>


#define MAX 10000
#define ASCII_COUNT 128

int *returnCharacterLocations(char s[], char findChar[]);

//Return first location of any character in string s2

//Issue: incorrect values are being printed
int main(void)
{
	int c, d, position;
	
	char inputLine[MAX];
	char lettersToFind[MAX];
	
	int letterCount[ASCII_COUNT] = { 0 };
	
	printf("Enter line: ");
	position = 0;
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		inputLine[position++] = c;
	}
	inputLine[position++] = '\0';
	
	printf("\nEnter characters to search for: ");
	position = 0;
	
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		lettersToFind[position++] = d;
	}
	lettersToFind[position++] = '\0';
	
	int *getCount = returnCharacterLocations(inputLine, lettersToFind);
	
	int m;
	for (m = 0; m < ASCII_COUNT; m = m + 1)
	{
		int count = *(getCount + m);
		if (count == -1 || count > 0)
		{
			printf("%c\t%d\n", m, count);
			
		}
	}
	
	return 0;
}

int *returnCharacterLocations(char s[], char findChar[])
{
	static int counts[ASCII_COUNT] = { 0 };
	
	int i, j, k;
	
	for (i = 0; findChar[i] != '\0'; i = i + 1)
	{
		for (j = 0; s[j] != '\0'; j = j + 1)
		{
			if (s[j] == findChar[i])
			{
				counts[findChar[i]] = j;
				break;
			}
		}
		if (s[j] == '\0')
		{
			counts[findChar[i]] = -1;
		}
	}
	
	return counts;
	
}
