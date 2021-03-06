#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100
#define MAX_SIZE 10000
#define MAX_WORD 100
#define NKEYS 32

static char buf[BUFSIZE];

static int bufp = 0;

static int negBuff = 0;


struct key {
	
	char *word;
	int count;
} keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"do", 0,
	"double", 0,
	"else", 0,
	"enum", 0,
	"extern", 0,
	"float", 0,
	"for", 0,
	"goto", 0,
	"if", 0,
	"int", 0,
	"long", 0,
	"register", 0,
	"return", 0,
	"short", 0,
	"signed", 0,
	"sizeof", 0,
	"static", 0,
	"struct", 0,
	"switch", 0,
	"typedef", 0,
	"union", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};



int binsearch(char *word, struct key tab[], int n);
int getword(char *word, int lim);
int getch(void);
void ungetch(int c);




int main(void)
{
	int n;
	char word[MAX_WORD];
	
	while (getword(word, MAX_WORD) != EOF)
	{
		if (isalpha(word[0]))
		{
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
			{
				printf("Index %d\n", n);
				keytab[n].count++;
			}
		}
	}
	
	//Problem: things are only being allocated to 'auto'
	for (n = 0; n < NKEYS; n = n + 1)
	{
		if (keytab[n].count > 0)
		{
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
		}
	}
	
	return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	
	//printf("low %d high %d\n", low, high);
	
	while (low <= high)
	{
		mid = (low + high) / 2;
		
		if ((cond = strcmp(word, tab[mid].word)) < 0)
		{
			high = mid - 1;
		}
		else if (cond > 0)
		{
			low = mid + 1;
		}
		else
		{
			//printf("Haha\n");
			//Gamimeno malaka
			return mid;
		}
		
		//printf("low %d mid %d high %d\n", low, mid, high);

	}
	return -1;
}

//A word is either a string of letters and digits beginnning with a letter
//Goal: handle string constants, comments, and preprocessor control lines by preventing then from being counted as keywords is there are keywords in them
//String constant: eg. "hello" (any string with quotations around it
//Comments start with // or /*
//Preprocessor control lines: eg. #include
int getword(char *word, int lim)
{
	int c;
	char *w = word;
	
	while (isspace(c = getch()));
	
	if (c != EOF)
	{
		*w++ = c;
	}
	
	//Check for string constants (they can go on for lines)
	if (c == '\"')
	{
		while ((c = getch()) != '\"')
		{
		}
		
	}
	
	//Check for underscores
	//How to terminate loop?
	//A. stop when a space is encountered?
	//B. stop when a '\n' is encountered?
	if (c == '_')
	{
		while ((c = getch()) != '\n')
		{
		}
	}
	
	//How will I handle number signs?
	//Ignore anything right after them unless it is a space
	if (c == '#')
	{
		//Ah I see, iterate through until you encounter a new line
		while((c = getch()) != '\n')
		{
		}
	}
	
	if (c == '/')
	{
		if ((c = getch()) == '*')
		{
			while ((c = getch()) != '/')
			{
			}
		}
		else
		{
			while ((c = getch()) != '\n')
			{
			}
		}
	}
	
	
	
	
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	
	while (--lim)
	{
		if (!isalnum(*w = getch()))
		{
			ungetch(*w);
			break;
		}
		w++;
	}
	
	*w = '\0';
	return word[0];
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
