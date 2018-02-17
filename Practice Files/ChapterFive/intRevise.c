

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAX_SIZE 10000

static char buf[BUFSIZE];

static int bufp = 0;

static int negBuff = 0;

int getch(void);
void ungetch(int c);
int getint(int *pn);


int main(void)
{
	int c, position;
	int lineInput[MAX_SIZE];
	
	printf("Enter integer to return: ");


	int k;
	for (k = 0; k < MAX_SIZE && (getint(&lineInput[k]) != EOF); k = k + 1)
	{
		printf("Enter integer to return: ");
	}
	
	
	//Prints out n -1 numbers, and now 1 number
	//Reason: m is not incrementing
	int m;
	for (m = 0; m < k; m++)
	{
		printf("%d", *(lineInput + m));	
	}

	
	
	
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

//Calls one integer per call
//End calls by pressing Ctrl Z and then pressing enter
//Issue (as stated in textbook): program interpets '-' and '-' as 0
int getint(int *pn)
{
	int c, sign, counter, negativeEncountered;
	
	counter = counter + 1;
	//Ignore whitespace
	while (isspace(c = getch()))
	{
	}
	
	
	//If c is not a number
	if (!isdigit(c) &&  c != EOF && c !='+' && c != '-')
	{
		//ungetch(c);
		return 0;
	}
		
	sign = (c == '-') ? -1 : 1;
	//printf("Sign: %d", sign);
	
	if (c == '+' || c == '-')
	{	
	        c = getch();
	        //Check if c is not a digit, then put either a positive or negative sign in the buffer
	        //buffer takes characters -_-
	        if (!isdigit(c)) {
			ungetch(sign == 1 ? '+' : '-');
			return 0;
		}
		//c = getch();
		//printf("Pos/Neg: %d\n", c);
	}


	for (*pn = 0; isdigit(c); c = getch())
	{
		*pn = 10 * *pn + (c - '0');
	}
	
	*pn  = *pn * sign;
		
	if (c != EOF)
	{
		ungetch(c);
	}
	
	
	//printf("%d\n", *pn);
	return c;
	
}


