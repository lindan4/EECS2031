

#include <stdio.h>


#define MAX_LENGTH 10000
#define ONE 1


char *excludingLetters(char main[], char exclude[]);
void copy(char s[], char t[]);

int main()
{
	char line[MAX_LENGTH];
	char excludingCharacters[MAX_LENGTH];
	
	int c, d;
	
	int position = 0;
	
	printf("\nEnter line: ");
	
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		line[position] = c;
		position = position + ONE;
	}
	line[position] = '\0';
	
	printf("\nEnter characters to delete: ");
	position = 0;
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		excludingCharacters[position] = d;
		position = position + ONE;
	}
	excludingCharacters[position] = '\0';
	
	char *pablo = excludingLetters(line, excludingCharacters);
	
	int j;
	for (j = 0; (*(pablo + j)) != '\0'; j = j + ONE)
	{
		//putchar(*(pablo + j));
	}
	
	return 0;
}

char *excludingLetters(char main[], char exclude[])
{
	int m, n, p;
	static char draftN[MAX_LENGTH];
	static char finalPoint[MAX_LENGTH];
	
	copy(main, draftN);
	
	for (m = 0; exclude[m] != '\0'; m = m + 1)
	{
		putchar(exclude[m]);
		putchar('\n');
		n = 0;
		for (p = 0; draftN[p] != '\0'; p = p + 1)
		{
			if (draftN[m] != exclude[p])
			{
				finalPoint[n] = draftN[m];
				//printf("%d", n);
				n = n + ONE;
			}
		}
		finalPoint[n] = '\0';
		copy(finalPoint, draftN);
	}
	return draftN;
}

void copy(char s[], char t[])
{
	int i;
	
	for (i = 0; s[i] != '\0'; i = i + ONE)
	{
		t[i] = s[i];
	}
	
	t[i] = '\0';
}

