

#include <stdio.h>

#define TWO 2

int invert(int x, int p, int n);

int toPower(int a, int b);

int main()
{
	int c, d, e;
	
	printf("Enter x (number): ");
	scanf("%d", &c);
	
	printf("\nEnter p (bit position): ");
	scanf("%d", &d);
	
	printf("\nEnter n (number of bits): ");
	scanf("%d", &e);
	
	int seeResult = invert(c, d, e);
	printf("\nResult: %d", seeResult);
	
	return 0;
}

int invert(int x, int p, int n)
{
	int extractValue, shiftExtract, inverted;
	if (n == 0)
	{
		return x;
	}
	else
	{
		extractValue = toPower(TWO, n) - 1;
		shiftExtract = extractValue << ((p + 1) - n);
		inverted = x ^ shiftExtract;
		
		return inverted;
	}
	
	
}

int toPower(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else if (b < 0)
	{
		return (1 / a) * toPower(a, b - 1);
	}
	else
	{
		return a * toPower(a, b - 1);
	}
}
