#include <stdio.h>

#define MAX_SIZE 5000

void strNCat(char *s, char *t);

int main(void)
{
	int c, d, position = 0;
	
	char *stringS = (char *) malloc(MAX_SIZE * sizeof(char));
	char *stringT = (char *) malloc(MAX_SIZE * sizeof(char));
	
	printf("Enter string s: ");
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		*(stringS + position) = c;
		position++;
	}
	*(stringS + position) = '\0';
	
	
	printf("Enter string t: ");
	position = 0;
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		*(stringT + position) = d;
		position++;
	}
	
	strNCat(stringS, stringT);
	printf("\n\n%s", stringS);
	
	return 0;
}

void strNCat(char *s, char *t)
{
	int startConcatenate = 0;
	
	while (*s != '\0')
	{
		s++;
	}
	
	while (*t != '\0')
	{
		*(s + startConcatenate) = *t;
		startConcatenate++;
		t++;
	}
	
	*(s + startConcatenate) = '\0';
}