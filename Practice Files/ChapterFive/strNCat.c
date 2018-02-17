#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000


void strncat(char *s, char *t, int n);

int main(void)
{
	int c, d, n, position;
	char *a, *b;
	
	a = (char *) malloc(MAX_SIZE * sizeof(char));
	b = (char *) malloc(MAX_SIZE * sizeof(char));
	
	printf("Enter string a: ");
	position = 0;
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		*(a + position) = c;
		position = position + 1;
	}
	
	*(a + position) = '\0';
	
	printf("\nEnter string b: ");
	position = 0;
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		*(b + position) = d;
		position = position + 1;
	}
	
	*(b + position) = '\0';
	
	printf("\nSpecify the amount of characters to append: ");
	scanf("%d", &n);
	
	strncat(a, b, n);
	
	int j;
	for (j = 0; *();)
	
	return 0;
}

void strncat(char *s, char *t, int n)
{
	void* startAddress = s;
	
	int count, tCount = 0;
	
	while (*s != '\0')
	{
		s++;
	}
	
	while (*t != '\0' && count < n)
	{
		*(s + tCount) = *(t + tCount);
		tCount = tCount + 1;
		count = count + 1;
	}
	*(s + tCount) = '\0';
	s = (char *) startAddress;
}
