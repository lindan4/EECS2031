

#include <stdio.h>

main()
{
	int c;
	int blankCount;
	
	blankCount = 0;
	
	printf("Enter a line of characters>");
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		if (c == ' ')
		{
			blankCount = blankCount + 1;
		}
	}
	
	printf("\n%d\n", blankCount);
	
}
