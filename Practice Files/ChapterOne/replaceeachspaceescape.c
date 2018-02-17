

#include <stdio.h>

main()
{
	int c;
	
	printf("Input value: ");
	while ((c = getchar()) != EOF)
	{
		while (c == '\t')
		{
			printf("\\t");
			c = getchar();
		}
		while (c == '\b')
		{
			printf("\\b");
			c = getchar();
		}
		while (c == '\\')
		{
			printf("\\\\");
			c = getchar();
		}
		putchar(c);
		/*
		if (c == '\t')
		{
			printf("\\t");
		}
		else if (c == '\b')
		{
			printf("\\b")
		}
		else if (c == '\\')
		{
			printf("\\\\");
		}
		else
		{
			putchar(c);
		}	
		*/
	}
	
	
}