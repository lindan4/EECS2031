

#include <stdio.h>

#define SPACES_PER_TAB 8

int returnTabToSpaceCount(int preTabCount);
void placeSpaces(int count);

int main()
{
	//Try to find an equation for the number of tabs
	
	
	int c, charCount;
	
	charCount = 0;
	
	printf("Enter a line with tabs>\n");
	while ((c = getchar()) != EOF && c != '\n')
	{
		if (c == '\t')
		{
			int getSpaces = returnTabToSpaceCount(charCount);
			placeSpaces(getSpaces);
			charCount = 0;
		}
		else
		{
			putchar(c);
			charCount = charCount + 1;
		}
	}
	return 0;
}
int returnTabToSpaceCount(int preTabCount)
{
	int spaces;
	if ((preTabCount % SPACES_PER_TAB) == 0)
	{
		spaces = SPACES_PER_TAB;
	}
	else
	{
		spaces = SPACES_PER_TAB - (preTabCount % SPACES_PER_TAB);
	}
	return spaces;
}
void placeSpaces(int count)
{
	for (int i = 0; i < count; i = i + 1)
	{
			putchar(' ');
	}	
}
