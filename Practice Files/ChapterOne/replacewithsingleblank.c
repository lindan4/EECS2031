

#include <stdio.h>

main()
{
	int c;
	int multiBlankCounter;
	int holder;
	
	multiBlankCounter = 0;
	
	printf("Enter input: ");
	
	//Try doing it without 'if' statements
	while ((c = getchar()) != EOF)
	{
		
		while (c == ' ')
		{
			c = getchar();
		}
		while (c != ' ')
		{
			putchar(c);
			c = getchar();
		}
		putchar(' ');

		/*
		if (c == ' ')	
		{
			putchar(' ');
			while ((c = getchar()) == ' ')
			{
			}
			putchar(c);
		}
		else
		{
			putchar(c);
		}
		*/

	}
	
}