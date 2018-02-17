#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];



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