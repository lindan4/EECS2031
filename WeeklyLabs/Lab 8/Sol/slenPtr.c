#include <stdio.h>
#include <stdlib.h>

char** alloc2D( int num_of_str, int str_len )
{

   char **st, i;

   /* Allocate an array of pointers, each pointing to a row. */
   st = ( char** ) malloc( num_of_str * sizeof( char* ) );
   if ( st == NULL ) {
	printf( "Insufficient memory!\n" );
	exit ( 1 );
   }

   /* Allocate each row. */
   for( i = 0; i < num_of_str; i++ ) {
     *(st + i) = ( char* ) malloc( str_len * sizeof( char ) );
   	 if ( *(st + i) == NULL ) {
	   printf( "Insufficient memory!\n" );
	   exit ( 1 );
   	}  /* if */
   } /* for */

   return( st );
}


void str_lengths( char **st, int num_of_str )
{
   int i, j;
   for( i = 0; i < num_of_str; i++ ) {
      for( j = 0; *(*(st + i) + j) != '\0'; j++ ) ;
      printf( "%s\t%d\n", *(st + i), j );
   }  /* for */
}


