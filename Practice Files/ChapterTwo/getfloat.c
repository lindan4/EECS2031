

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

#define dummySize 10000

static char buf[BUFSIZE];

static int bufp = 0;

int getch(void);
void ungetch(int c);
double getfloat(int *pn);
int getCharArrayLength(char s[]);

int main()
{
	
	int input;
	char line[dummySize];
	
	//printf("Input double number: ");
	
	
	return 0;
}

int getch(void)
{
	//If there is input in the buffer then return it, else fetch a char from stdio
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}

double getfloat(int *pn)
{
	int c;
	double output, sign;
	
	while (isspace(c = getch()))
	{
	}
	
	if (isdigit(c) && c != EOF)
	{
			
	}
	else if (!isdigit(c) && c != EOF)
	{
		
	}
}

int getCharArrayLength(char s[])
{
	int i;
	
	for (i = 0; s[i] != '\0'; i = i + 1)
	{
		i = i + 1;
	}
	
	return i;
}
