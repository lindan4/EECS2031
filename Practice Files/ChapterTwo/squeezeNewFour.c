
#include <stdio.h>

#define MAX 10000

void squeeze(char s1[], char s2[]);

int main(void)
{
	int c, d, position;
	
	char inputLine[MAX];
	char filterLine[MAX];
	
	
	printf("Input line: ");
	position = 0;
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		inputLine[position++] = c;
	}
	
	inputLine[position++] = '\0';
	
	printf("\nEnter line of characters to remove: ");
	position = 0;
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		filterLine[position++] = d;
	}	
	filterLine[position++] = '\0';
	
	squeeze(inputLine, filterLine);
	
	printf("\n%s", inputLine);

	
	
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	
	//Get letter to filter out
	for (i = 0; s2[i] != '\0'; i = i + 1)
	{
		k = 0;
		for (j = 0; s1[j] != '\0'; j = j + 1)
		{
			//if letter to be filtered out is different from current letter
			if (s1[j] != s2[i])
			{
				//Append it to the start of the array
				s1[k++] = s1[j];
				
			}
			//else you skip the letter
			
			
		}
	}
	s1[k++] = '\0';
}
