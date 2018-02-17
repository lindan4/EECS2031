


#include <stdio.h>


main()
{
	int tabs, newlines, blanks;
	int c;
	
	tabs = 0;
	newlines = 0;
	blanks = 0;
	
	
	printf("Input a sentence:\n");
	
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			tabs = tabs + 1;
		}
		
		if (c == '\n')
		{
			newlines = newlines + 1;
		}
		
		if (c == ' ')
		{
			blanks = blanks + 1;
		}
	}
	
	printf("There are %d tabs, %d new lines, and %d blanks\n", tabs, newlines, blanks);
	
}