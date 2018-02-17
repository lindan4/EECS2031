#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define TEN 10


int getLength(char *t);
int toPower(int a, int b);
int atoarecur(char *s);


int main(void)
{
	int c, position;
	char *numberRoom = (char *) malloc(MAX_SIZE * sizeof(char));	
	printf("Enter number: ");
	
	position = 0;
	while (((c = getchar()) != EOF) & (c != '\n'))
	{
		*(numberRoom + position) = c;
		position++;
	}
	*(numberRoom + position) = '\0';
	
	printf("\n%d", atoarecur(numberRoom));
	
	return 0;
}


int getLength(char *t)
{
	int counter = 0;
	while (*t != '\0')
	{
		t++;
		counter++;
	}
	return counter;
}

int toPower(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else if (b > 0)
	{
		return a * toPower(a, b - 1);
	}
	else
	{
		return a * toPower(a, b + 1);
	}
	return 0;
}

int atoarecur(char *s)
{
	int powerOf = toPower(10, getLength(s) - 1);
	
	if (*s == '\0')
	{
		return 0;
	}
	else if (*s == '-')
	{
		return -1 * atoarecur(++s);
	}
	else if (*s == '+')
	{
		return atoarecur(++s);
	}
	else
	{
		//printf("%c\n", *s);
		return ((*s - '0') * powerOf) + atoarecur(++s);
	}
}

