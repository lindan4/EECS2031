
#include <stdio.h>

#define MAX 10000
#define THIRTY_TWO 32

void lower(char s[]);

int main()
{
	int c, position;
	char line[MAX];
	
	position = 0;
	
	printf("Enter a line of characters: ");
	
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		line[position++] = c;
	}
	line[position] = '\0';
	lower(line);
	
	printf("\n%s", line);
	
	return 0;
}

void lower(char s[])
{
	int j = 0;
	
	while (s[j] != '\0')
	{
		s[j] = (s[j] <= 'Z' && s[j] >= 'A') ? s[j] +  THIRTY_TWO : s[j];
		j = j + 1;
	}
}
