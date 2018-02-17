#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000



static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *lineptr[MAX_LINES];

void swap(char *v[], int i, int j);
int readlines(char *lineptr[], int maxlines, char lin[]);
void writelines(char *lineptr[], int nlines);
int getline(char *s, int lim);
void copy(char *s, char *t);
void qsort(char *lineptr[], int left, int right);
char *alloc(int n);


//Task: rewrite readlines to store lines in an array supplied from main
//Issue: program prints out recent line n times
int main(void)
{
	int nlines;
	char storeLines[ALLOCSIZE];
	
	//How does nlines increment if you keep on initializing it to 0?
	//It stays within the method
	if ((nlines = readlines(lineptr, MAX_LINES, storeLines)) >= 0)
	{
		printf("nlines: %d\n", nlines);
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("Error: input too big to sort\n");
		return 1;
	}
	
	return 0;
}

void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

//Read input lines
int readlines(char *lineptr[], int maxlines, char lin[])
{
	int len, nlines;
	char *p, line[MAXLEN];
	p = lin;
	
	nlines = 0;
	
	while ((len = getline(line, MAXLEN)) > 0)
	{
		//Alloc is here
		//Fix this up
		//Soultion: mimic condition used in alloc
		if (nlines >= maxlines || ALLOCSIZE + lin - p < len)
		{
			return -1;
		}
		else
		{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
			p = p + len;
		}
	}
	return nlines;
}

//Write output lines 
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
	{
		printf("%s\n", *lineptr++);
	}
	
}

int getline(char *s, int lim)
{
	int c, i;
	
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i = i + 1)
	{
		*(s + i) = c;
	}
	
	if (c == '\n')
	{
		*(s + i) = c;
		++i;
	}
	*(s + i) = '\0';
	return i;
}

void copy(char *to, char *from)
{
	int i = 0;
	
	while ((*(to + i) = *(from + i)) != '\0')
	{
		i++;
	}
}
void qsort(char *v[], int left, int right)
{
	int i, last;
	if (left >= right)
	{
		return;
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i = i + 1)
	{
		if ((strcmp(v[i], v[left])) < 0)
		{
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

//Return pointers to n characters
char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n; 
	}
	else
	{
		return 0;
	}
	
}


