


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void pointerStrCat(char *s, char *t);
int pointerStrEnd(char *j, char *k);

int main(void)
{
	int c, d, position;
	char *a, *b;
	
	position = 0;
	
	a = (char *)malloc(MAX_SIZE * sizeof(char));
	b = (char *)malloc(MAX_SIZE * sizeof(char));
	
	
	printf("Enter string s: ");
	while (((c = getchar()) != EOF) && (c != '\n'))
	{
		*(a + position) = c;
		position = position + 1;	
	}
	*(a + position) = '\0';
	
	printf("\nEnter string t: ");
	position = 0;
	
	
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		*(b + position) = d;
		position = position + 1;
	}
	

	*(b + position) = '\0';
	//printf("\nAddress of a: %d", a);
	pointerStrCat(a, b);
	//printf("\nAddress of a after: %d\n\n", a);
	
	int j;
	printf("Strcat: ");
	for (j = 0; *(a + j) != '\0'; j = j + 1)
	{
		printf("%c", *(a + j));
	}
	putchar('\n');

	
	return 0;
}

void pointerStrCat(char *s, char *t)
{
	void* start = s;
	//printf("\nAddress of start: %d\n", start);

	int sCount, tCount = 0;
	
	//don't do *(s++) nor *s++
	while (*s != '\0')
	{
		s++;
		//printf("S is %c\n", *s);
	}
	
	
	while (*(t + tCount) != '\0')
	{
		*(s + tCount) = *(t + tCount);
		tCount = tCount + 1;
	}
	
	*(s + tCount) = '\0';
	s = (char * )start;
	//printf("\nAddress of s after reassigning: %d", s);
}

int pointerStrEnd(char *j, char *k)
{
	void* kStart = (char *)k;
	while (*j != '\0')
	{
		while (*j == *k)
		{
			if (*j == '\0' && k == '\0')
			{
				return 1;
			}
			j++;
			k++
		}
		k = kStart;
		j++;
	}
	return 0;

}