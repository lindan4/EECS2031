
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAX_SIZE 10000

static char buf[BUFSIZE];

static int bufp = 0;

//Incomplete

int getch(void);
void ungetch(int c);

float getfloat(float *pn);

int main()
{
	return 0;
}

int getch(void)
{
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


//Special case: consider having '.'
//If there is a decimal, then start dividing by 10 instead of multiplying by 10
//Else you continue with multiplying by 10, etc
float getfloat(float *pn)
{
	int c, sign, decimalCount;
	while (isspace(c = getch()));
	
	decimalCount = 0;
	
	if (c == '.')
	{
		decimalCount = decimalCount + 1;
		if (decimalCount > 1)
		{
			ungetch(c);
		}
		else
		{
			c = getch();
		}
	}
	else
	{	
		if (!isdigit(c) && c != EOF && c != '+' && c != '-')
		{
			ungetch(c);
			return 0;
		}
		
		while (isdigit(c))
		{
			
		}
		
	}
		
	sign (c == '-') ? -1 : 1;
	
	if (c == '+' || c == '-')
	{
		ungetch(c);
	}
	
	*pn = *pn * sign;
	
	if (c != EOF)
	{
		ungetch(c);
	}
	
	
	return c;	
	
	
}

