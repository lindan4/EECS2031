#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5000

int strncopy(char *s, char *t, int n);

int main(void)
{
	
	int c, d, n, position, result;
	char *a, *b;
	
	a = (char *) malloc(MAX_SIZE * sizeof(char));
	b = (char *) malloc(MAX_SIZE * sizeof(char));
	
	position = 0;
	printf("Enter first word a: ");
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		*(a + position) = c;
		position = position + 1;
	}
	
	*(a + position) = '\0';
	
	printf("\nEnter the second word b: ");
	position = 0;
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		*(b + position) = d;
		position = position + 1;
	}
	*(b + position) = '\0';
	
	printf("\nEnter the first n number of characters you want to compare: ");
	scanf("%d", &n);
	
	result = strncopy(a, b, n);
	printf("\nThe difference is %d", result);
	
	return 0;
	
}

//Compare n characters from two strings and return the char difference between both
int strncopy(char *s, char *t, int n)
{
	int count = 0;
	while (*s == *t)
	{
		s++;
		t++;
		count++;
		if (*s == '\0' || count >= n)
		{
			//printf("It goes here");
			return 0;
		}
	}
	return *s - *t;
}
