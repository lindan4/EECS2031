

#include <stdio.h>

main()
{
	int c, inc;
	
	inc = 0;
	
	printf("Input lines (Press Ctrl-D to terminate input entry and to return the result)\n");
	while ((c = getchar()) != EOF)
	{
		//No string!!
		if (c == '\n')
		{
			inc = inc + 1;
		}
	}
	printf("%d lines have been found\n", inc);
}
