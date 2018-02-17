

#include <stdio.h>


#define MAX 10000

void squeeze(char s1[], char s2[]);

int main()
{
	char line[MAX];
	char filterOut[MAX];
	
	int c, d;
	int position = 0;
	printf("Enter line: ");
	
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		line[position] = c;
		position = position + 1;
	}
	line[position] = '\0';

	position = 0;
	printf("Enter the characters to remove: ");
	
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		filterOut[position] = d;
		position = position + 1;
	}
	filterOut[position] = '\0';

	
	//squeeze(line, filterOut);

	
	for (int p = 0; line[p] != '\0'; p = p + 1)
	{
		printf("%s", line);
	}
	
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	
	k = 0;
	for (i = 0; s1[i] != '\0'; i = i + 1)
	{
		for (j = 0; (s1[i] != s2[j]) && (s2[j] != '\0');  j = j + 1)
		{
			if (s2[j] == '\0')
			{
				s1[++k] = s1[i];
			}
		}
		
	}
	s1[k] = '\0';	
}
