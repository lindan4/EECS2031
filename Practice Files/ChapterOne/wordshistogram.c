

#include <stdio.h>

main()
{
	//1. Recognize a word
	//2. Have counter to check each character
	//3. Based on the value of the counter, append '*' at the end of the word (perhaps after a \t)
	
	int c, i;
	int wordLengthCounter;
	
	
	wordLengthCounter = 0;
	
	printf("Input sentence(s): ");
	while ((c = getchar()) != EOF)
	{
		if (c == '.' || c == ',' || c == '?' || c == '!')
		{
		}
		else if (c == ' ' || c == '\t' || c == '\n')
		{
			putchar('\t');
			putchar('\t');
			for (i = 0; i < wordLengthCounter; i = i + 1)
			{
				putchar('*');
			}
			putchar('\n');
			wordLengthCounter = 0;
		}
		else
		{
			wordLengthCounter = wordLengthCounter + 1;
			putchar(c);
		}
			
	}
}
