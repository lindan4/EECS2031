#include <stdio.h>

int main(void)
{
	
	char lo = 's';
	char *p = &lo;
	
	printf("%c", *p);
	return 0;
}
