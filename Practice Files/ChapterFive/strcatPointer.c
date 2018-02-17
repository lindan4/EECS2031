
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void strcat(char *, char *);


//Issue program crashes
int main(void)
{
	int c, d, position;
	char *a, *b;
	
	position = 0;
	
	a = (char *) malloc(MAX_SIZE * sizeof(int));
	b = (char *) malloc(MAX_SIZE * sizeof(int));
	
	printf("Enter string s: ");
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		*(a + position) = c;
		position = position + 1;
	}
	*(a + position) = '\0';
	
	position = 0;
	
	printf("\nEnter string t: ");
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		*(b + position) = d;
		position = position + 1;
	}
	
	*(b + position) = '\0';
	
	strcat(&a, &b);
	
	int j;
	for (j = 0; *(a + j) != '\0'; j = j + 1)
	{
		printf("%s", *(a + j));
	}
	return 0;
}

void strcat(char *s, char *t)
{
	int tCount;
	
	
	while (*s != '\0')
	{
		s = s + 1;
	}
	
	tCount = 0;

	while (*(t + tCount) != '\0')
	{
		*(s + tCount) = *(t + tCount);
		tCount = tCount + 1;
	}
	
	*(s + tCount) = '\0';
}

