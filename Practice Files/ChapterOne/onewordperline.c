

#include <stdio.h>


//Ditto
main()
{
	#define IN 1
	#define OUT 0
	
	int c;
	
	
	printf("Input line: ");
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		if (c == '\n' || c == '\t' || c == ' ')
		{
			while(c == '\n' || c == '\t' || c == ' ')
			{
				c = getchar();
			}
			putchar('\n');
			putchar(c);
		}
		else
		{
			putchar(c);
		}
		/*
		if (c == '\n' || c == '\t' || c == ' ')
		{
			printf("\n");
			while((c = getchar() == ' '))
			{
			}
			
		}
		else
		{
			putchar(c);
		}
		*/
		//printf("Input line: ");
	}
}
