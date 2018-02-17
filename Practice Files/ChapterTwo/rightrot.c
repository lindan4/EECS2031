

#include <stdio.h>

#define TWO 2

int rightrot(int x, int n);
int bitCount(int d);
int toPower(int a, int b);

int main()
{
	int i, j, k;
	
	printf("Enter the number to rotate: ");
	scanf("%d", &i);
	
	printf("\nEnter the amount of bit positions to rotate it by: ");
	scanf("%d", &j);
	
	k = rightrot(i, j);
	
	printf("\nThe rotated number becomes: %d", k);
	
	
	return 0;
}

int rightrot(int x, int n)
{
	int mask, filteredBits, amtFilt, shiftedFilteredBits;
	
	
	if (n == 0 || x == 0)
	{
		return 0;
	}
	else
	{
		mask = toPower(TWO, n) - 1;	
		printf("\n%d", mask);

	
		filteredBits = x & mask;
		printf("\nMasking: %d", filteredBits);

		
		
		shiftedFilteredBits = filteredBits << (sizeof(int) - n);
		printf("\n%d", shiftedFilteredBits);

	
		x = x >> n;
		//printf("\n%d", x);

	
		return x | shiftedFilteredBits;
		
	}
	
}

int bitCount(int d)
{
	int i;
	
	for (i = 0; d != 0; i = i + 1)
	{
		d = d >> 1;
	}
	//printf("\nCount: %d", i);

	return i;
}

int toPower(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else if (b < 0)
	{
		return (1 / a) * toPower(a, b + 1);
	}
	else
	{
		return a * toPower(a, b - 1);
	}
}
