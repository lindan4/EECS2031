

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10000


char *squeeze(char s[], char seeFor[]);
void copy(char a[], char b[]);

int main()
{
	#define ONE 1
	
	int c, d;
	int i, j = 0;
	
	char line[MAX_LENGTH];
	char filterCharacters[MAX_LENGTH];
	
	
	printf("Enter a line of characters:\n");
	
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		line[i] = c;
		++i;
	}
	i = i + 1;
	line[i] = '\0';
	
	printf("\nEnter characters to filter out from the sentence: ");
	
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		filterCharacters[j] = d;
		j++;
	}
	
	filterCharacters[j] = '\0';
	
	
	
	//new pointer holds the address
	char *newPointer = squeeze(line, filterCharacters);
	
	int m;
	
	for (m = 0; m < i; m = m + 1)
	{
		putchar(*(newPointer + m));
	}
	
	return 0;
}

//Solution: delete is not a primitive

//Another problem: 
char *squeeze(char s[], char seeFor[])
{
	static char filteredArray[MAX_LENGTH];
	static char endArray[MAX_LENGTH];
	
	//copy(s, filteredArray);
	
	int k, p, q, r;
	int n, holdLastPosition;
	
	copy(s, endArray);
	

	for (p = 0; seeFor[p] != '\0'; p = p + 1)
	{
			n = 0;
			for (k = 0; endArray[k] != '\0'; k = k + 1)
			{
				if (endArray[k] != seeFor[p])
				{
					filteredArray[n] = s[k];
					n = n + 1;
				}
			}
			filteredArray[n] = '\0';
			n = n + 1;
			copy(filteredArray, endArray);

	}
	
	return endArray;
}

void copy(char a[], char b[])
{
	int i;
	
	for (i = 0; a[i] != '\0'; i = i + 1)
	{
		b[i] = a[i];
	}
	b[i] = '\0';
}


