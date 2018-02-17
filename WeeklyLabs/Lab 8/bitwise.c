#include <stdio.h>
#include <stdlib.h>

main()
{
   int x;
   printf( "Size of int is %d bytes.\n", sizeof( x ) );

   x = 0xFFFF;
   x = x & 0177; /* set to zero all but the low-order 7 bits of x */
   printf( "x = 0x%X\n", x );

   x = 0;
   int SET_ON = 0xF0F0;
   x = x | SET_ON; /* set to 1 in x the bits that are set to 1 in SET_ON */
   printf( "x = 0x%X\n", x );

   x = 0xFFFF;
   x = x & ~077; /* set the last 6 bits of x to zero */
   printf( "x = 0x%X\n", x );
}

