#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define VARIABLE 'A'

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];


//Functions
int getch(void);
void ungetch(int c);
void ungets(char *b);

int getop(char s[]);
void push(double t);
double pop(void);
void printTop(void);
void duplicateTop(void);
void swapTopElements(void);
void clearStack(void);

int isNumber(char *t);

/*Reverse Polish calculator*/
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	
	//Pop variable later
	double valueToStore;
	int singleVariable;
	//Store variable here
	double variableStorage[26];
	
	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case VARIABLE:	
			if (type >= 'a' && type <= 'z')
			{
				type = type - 32;
			}
			singleVariable = type - 'A';
			push(variableStorage[singleVariable]);
			
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
			{
				push(pop() / op2);
			}
			else
			{
				printf("error: zero divisor\n");
			}
			break;
		case '=':
			//Get two operands
			valueToStore = pop();
			variableStorage[singleVariable] = valueToStore;
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
			{
				push(pop() % op2);
			}
			else
			{
				printf("error: zero divisor");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			
			printf("error: unknown command %s\n", s);
			
			break;
		}
	}
	
	return 0;
}

int getch(void)
{
	return (buf > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
		if (c != EOF)
		{
			buf[bufp++] = c;
		}
		
	}
}

void ungets(char *b)
{
	while (*b != '\0')
	{
		ungetch(*b);
		b++;
	}
}

//Get next operator or numeric command
int getop(char s[])
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
	{
	}
	s[1] = '\0';
	
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return VARIABLE;
	}
	
	if (!isdigit(c) && c != '.')
	{
		return c;
	}
	i = 0;
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getch()))
		{
		}
	}
	
	if (c == '.')
	{
		while (isdigit(s[++i] = c = getch()))
		{
		}
	}
	s[i] = '\0';
	
	if (c != EOF)
	{
		ungetch(c);
	}
	
	return NUMBER;
}

//Put value t on top of stack
void push(double t)
{
	if (sp < MAXVAL)
	{
		val[sp++] = t;
	}
	else
	{
		//%g is double                                                   
		printf("Error: stack full, can't push %g\n", t);
	}
}

//Remove and return top value of stack
double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("Error: stack empty\n");
		return 0.0;
	}
}

void printStack(void)
{
	int i;
	for (i = 0; i < sp; i = i + 1)
	{
		printf("Stack item %d %lf\n", i, val[i]);
	}
}

void printTop(void)
{
	int valToPrint = sp - 1;
	if (sp == 0)
	{
		printf("Error: stack empty\n");
	}
	else
	{
		printf("Top value: %lf\n", sp, val[valToPrint]);
	}
}

void duplicateTop(void)
{
	int topVal;
	double topValue;
	
	if (sp == 0)
	{
		printf("Error: stack empty\n");
	}
	else
	{
		topVal = sp - 1;
		topValue = val[topVal++];
		//printf("topValue: %lf\n", topValue);
		val[sp++] = topValue;
	}
}

void swapTopElements(void)
{
	double temp;
	int topVal = sp - 1;
	
	temp = val[topVal];
	val[topVal] = val[topVal - 1];
	val[topVal - 1] = temp;
}

void clearStack(void)
{
	int i;
	for (i = 0; i < sp; i = i + 1)
	{
		val[i] = 0.0;
	}
	sp = 0;
}

int isNumber(char *t)
{
	while (*t != '\0')
	{
		if (!(*t >= '0' && *t <= '9'))
		{
			return 0;
		}
		t++;
	}
	return 1;
	
}