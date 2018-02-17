/***************************************
* EECS2031 – Lab 2                     *
* File name: lab2b.c                   *
* Author: Last name, first name        *
* Email: Your email address            *
* Login ID: Your EECS login ID         *
****************************************/

#include <stdio.h>
#define MAX_SIZE 100

void main() {
	int num[ MAX_SIZE ], min, max;
	int n, count = 0;
	
	printf( "Enter the next array element>" );
	scanf( "%d", &n );
	num[ count++ ] = n;
	min = n;
	max = n;
	while( n != 0 && count < MAX_SIZE ) {
		printf( "Enter the next array element>" );
		scanf( "%d", &n );
		num[ count++ ] = n;
		if (n < min)
			min = n;
		if (n > max)
			max = n;
	} 
	printf( "%d\t%d\n", max, min );
}