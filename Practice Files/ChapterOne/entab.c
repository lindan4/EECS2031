

#include <stdio.h>


#define GENERAL_SPACES_FOR_TAB 8

int main()
{
	/* 1 = 7 spaces for tab
	   2 = 6 spaces for tab
	   3 = 5 spaces for tab
	   4 = 4 spaces for tab
	   5 = 3 spaces for tab
	   6 = 2 spaces for tab
	   7 = 1 space for tab
	   8 = 8 spaces for tab
	   */
	   
	int c, spaceCount, characterCount;
	
	spaceCount = 0;
	characterCount = 0;
	
	printf("Enter a line with multiple spaces>\n");
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		if (c == ' ')
		{
			spaceCount = 0;
			while (c == ' ')
			{
				spaceCount = spaceCount + 1;
				c = getchar();
			}
			if (characterCount == (GENERAL_SPACES_FOR_TAB - (spaceCount % GENERAL_SPACES_FOR_TAB)))
			{
				putchar('\t');
				spaceCount = 0;
			}
			else
			{
				for (int j = 0; j < spaceCount; j = j + 1)
				{
					putchar(' ');
				}
			}
			putchar(c);
			characterCount = 1;

		}
		else
		{
			putchar(c);
			characterCount = characterCount + 1;
		}
		
	}
		
	return 0;
}
