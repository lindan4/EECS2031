

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000


int pointerStrEnd(char *j, char *k);
int main(void)
{
	int c, d, position, result;
	char *a, *b;
	
	a = (char *) malloc(MAX_SIZE * sizeof(char));
	b = (char *) malloc(MAX_SIZE * sizeof(char));
	
	printf("Enter string s: ");
	position = 0;
	
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		*(a + position) = c;
		position = position + 1;
	}
	*(a + position) = '\0';
	
	printf("\nEnter string t to check for: ");
	position = 0;
	
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		*(b + position) = d;
		position = position + 1;
	}
	
	result = pointerStrEnd(a, b);
	
	printf("It turns out that the string t %s at the end of s", (result == 1) ? "does appear" : "does not appear");
	
	return 0;
}

int pointerStrEnd(char *j, char *k)
{
	void* kStart = (char *)k;
	while (*j != '\0')
	{
		while (*j == *k)
		{
			if (*j == '\0' && *k == '\0')
			{
				return 1;
			}
			j++;
			k++;
		}
		k = (char *)kStart;
		j++;
	}
	putchar('\n');
	return 0;

}