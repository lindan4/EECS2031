#include <stdio.h>

#define TEN 10

double toPower(int a, int b);

main()
{
	double my_double;
	signed int k;
	printf("Enter an integer>");
	scanf("%d", &k);
	
	my_double = toPower(TEN, k);
	

	printf("%.15lf\n", my_double);
}

double toPower(int a, int b)
{
	double compute;
	
	if (b == 0)
	{
		return 1;
	}
	else if (b < 0)
	{
		compute = (double)1 / (double)a;
		return compute * toPower(a, b + 1); 
	}
	else
	{
		compute = (double)a;
		return compute * toPower(a, b - 1);
	}
}
