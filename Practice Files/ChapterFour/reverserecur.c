#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int getLength(char *t);
void reverseRecur(char *s);


int main(void)
{
	int c, position;
	
	char *inputString = (char *) malloc(MAX_SIZE * sizeof(char));
	
	printf("Input string to reverse: ");
	position = 0;
	
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		*(inputString + position) = c;
		position++;
	}
	
	*(inputString + position) = '\0';
	reverseRecur(inputString);
	
	printf("\n%s", inputString);
	
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

void reverseRecur(char *s)
{
	char temp;
	int sLength = getLength(s) - 1;
	
	if (*s == '\0')
	{
		//Do nothing and back up
	}
	else
	{
		printf("\n%c", *s);
		reverseRecur(s + 1);
		
		//Issue: order is not correct
		
		temp = *s;
		*s = *(s + sLength);
		*(s + sLength) = temp;
		putchar('\n');
		printf("\n%c", *(s + sLength));

	}
	
}
