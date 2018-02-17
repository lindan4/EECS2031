/***************************************
* EECS2031 – Lab 3                     *
* File name: lab3c.c                   *
* Author: Last name, first name        *
* Email: Your email address            *
* Login ID: Your EECS login ID         *
****************************************/

#include <stdio.h>

double power ( int p );

main()
{
   int k;
   double my_double;
   
   scanf( "%d", &k );

   /* Add your code here */
   my_double = power( k );
   /* Note: You do not have to create a function here. */
   /* In big programs, functions enhance code readability and reusability. */
   
   printf( "%.15lf\n", my_double );
}

double power ( int p )
{
   double x = 1.0;
   int i;
   
   if (  p > 0 )   
      for ( i = 1; i <= p; i++ )
         x = x * 10;
   else  /* p < 0 */
      for ( i = 1; i <= -p; i++ )
         x = x / 10; 
   return ( x );           
}

