#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void strncopy(char *s, char *t, int n);

//Rewrite strncopy, strncat, and strncmp
int main(void)
{
	int c, d, n, position;
	char *a, *b;
	
	a = (char *) malloc(MAX_SIZE * sizeof(char));
	b = (char *) malloc(MAX_SIZE * sizeof(char));
	
	printf("\nEnter string b: ");
	position = 0;
	
	while (((d = getchar()) != EOF) && (d != '\n'))
	{
		*(b + position) = d;
		position = position + 1;
	}
	*(b + position) = '\0';
	
	printf("Specify first n amounts of characters to copy over: ");
	scanf("%d", &n);
	
	strncopy(a, b, n);
	
	printf("\nCopied over text: ");
	for (position = 0; *(a + position) != '\0'; position = position + 1)
	{
		printf("%c", *(a + position));
	}
	
	putchar('\n');
	
	return 0;
}

//copy n characters from t to s
void strncopy(char *s, char *t, int n)
{
	void* sAddress = s;
	int count = 0;
	
	while (*t != '\0' && count < n)
	{
		*s = *t;
		s++;
		t++;
		count = count + 1;
	}
	*(s + count) = '\0';
	s = (char *) sAddress;
}
