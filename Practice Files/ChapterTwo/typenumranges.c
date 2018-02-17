

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int unsignedMin = 0;

	printf("Ranges:\n\n");
	printf("Signed char: %d %d\n", CHAR_MIN, CHAR_MAX);
	printf("Unsigned char: %d %u\n", unsignedMin, UCHAR_MAX);
	printf("Signed short: %d %d\n", SHRT_MIN, SHRT_MAX);
	printf("Unsigned short: %d %u\n", unsignedMin, USHRT_MAX);
	printf("Signed int: %d %d\n", INT_MIN, INT_MAX);
	//What????
	printf("Unsigned int: %d %u\n", unsignedMin, UINT_MAX);
	printf("Signed long: %d %d\n", LONG_MIN, LONG_MAX);
	printf("Unsigned long: %d %u\n", unsignedMin, ULONG_MAX);
	
	//Floats and doubles
	printf("Float: %.10f %.10f\n", FLT_MIN, FLT_MAX);
	printf("Double: %.10lf %.10lf\n", DBL_MIN, DBL_MAX);
	
	printf("\nSize of types:\n\n");
	printf("Size of short: %d bytes\n", sizeof(short));
	printf("Size of char: %d bytes\n", sizeof(char));
	printf("Size of int: %d bytes\n", sizeof(int));
	printf("Size of long: %d bytes\n", sizeof(long));
	printf("Size of float: %d bytes\n", sizeof(float));
	printf("Size of double: %d bytes\n", sizeof(double));
	printf("Size of long double: %d bytes\n", sizeof(long double));
	
	return 0;
}
