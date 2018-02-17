

#include <stdio.h>

main()
{
	#define SIZE 10000
	
	int c, position, counter;
	char line[SIZE];
	
	position = 0;
	counter = 0;
	printf("Input charcters to reverse: ");
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		line[counter] = c;
		counter = counter + 1;
	}
	
	while (counter >= 0)
	{
		putchar(line[counter]);
		counter = counter - 1;
	}
}

