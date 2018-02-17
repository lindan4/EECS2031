/***********************************
* EECS 2031 - Assignment 2
* Filename: mm.c
* Author: Thillanayagam, Lindan
* Email: lindan4@my.yorku.ca	 	
* Login ID: lindan4	
************************************/


#include <stdio.h>
#include <stdlib.h>


/***************** DO NOT USE ARRAY INDEXING *****************/
/************** USE ONLY POINTERS IN THIS FILE ***************/

/* You may define additional functions and local variables. */
int getLength(char *s)
{
	int count = 0;
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return count;
}

int multiplySingleMat(int *a, int *b, int length)
{
	int i;
	int sum = 0;
	for (i = 0; i < length; i = i + 1)
	{
		sum = sum + (*(a + i) * *(b + i));
	}
	return sum;
}

void prtMatrix( int **a, int nrows, int ncols )
{

   int i, j;
   for ( i = 0; i < nrows; i++ ) {
	for ( j = 0; j < ncols; j++ )
	   printf( "%5d", a[i][j] );
	printf( "\n" );
   }
   printf( "\n" );

}

int toIntNumber(char *s)
{
	int i;
	int holdSum = 0;
	char digitHold;
	
	const int TEN = 10;
	
	for (i = 0; *(s + i) != '\0'; i = i + 1)
	{
		digitHold = *(s + i);
		if (digitHold >= '0' && digitHold <= '9')
		{
			digitHold = digitHold - '0';
			holdSum = (holdSum * TEN) + digitHold;
		}
	}
	return holdSum;
}

/* 
   Save the three command-line arguments into nr1, nc1 and nc2.
 */

void get_args( char **argv, int *nr1, int *nc1, int *nc2 )
{

   /*************** ADD YOUR CODE HERE ***************/
   *nr1 = toIntNumber(*(argv + 1));
   *nc1 = toIntNumber(*(argv + 2));
   *nc2 = toIntNumber(*(argv + 3));

}




/*
   Initialize a 2-dimensional array.  
   Element (i, j) is assigned value i+j.
 */

void initMatrix ( int **a, int nrows, int ncols )
{

   /*************** ADD YOUR CODE HERE ***************/
   
   //(i th row, j th column),
   int i, j;
   
   int sum = 0;
   for (i = 0; i < nrows; i = i + 1)
   {
   	   for (j = 0; j < ncols; j = j + 1)
   	   {
   	   	  *(*(a + i) + j) = i + j;
   	   }
   }
}





/* 
   Multiply arrays a and b.  
   Array a has nr1 rows and nc1 columns.
   Array b has nc1 rows and nc2 columns.
   Allocate an array c having nr1 rows and nc2 columns.
   Compute a x b and store the result in array c.
   Return array c.
   If an error occurs (e.g., insufficient memory), return NULL pointer.
 */


int **matrix_mult( int **a, int **b, int nr1, int nc1, int nc2 )
{

   /*************** ADD YOUR CODE HERE ***************/
   
   int i, j, k, m;
   int entryHolderA, entryHolderB, entryHolderC;
   
   
   int *holdRow = (int *) malloc(nc1 * sizeof(int));
   int *holdColumn = (int *) malloc(nc1 * sizeof(int));
   
   int **resultingMat = (int **) malloc(nr1 * sizeof(int *));
   
   //Number of columns in A = Number of columns in B
   if (resultingMat == NULL)
   {
   	   return NULL;
   }
   else
   {
   	   for (k = 0; k < nr1; k = k + 1)
   	   {
   	   	   *(resultingMat + k) = (int *) malloc(nc2 * sizeof(int));
   	   	   if (*(resultingMat + k) == NULL)
   	   	   {
   	   	   	   return NULL;
   	   	   }
   	   }
   	   **resultingMat = 0;
   
   	   if (a == NULL || b == NULL)	   
   	   {
   	   	   return NULL;
   	   }
   	   else
   	   {
   	   	   
   	   	   //1 2	1 2 3
   	   	   //3 4	3 4 5
   	   	   /*Steps:
   	   	     1. Get (i, j) from B
   	   	     2. Get (i, j) from A
   	   	     3. Multiply both and then store
   	   	     4. Get (i, j + 1) from B
   	   	     5. Get (i + 1, j) from A
   	   	     6. Multiply both and then store
   	   	     7. Get (i, j + 2) from B
   	   	     8. Get (i + 2, j) from A
   	   	     
   	   	     9. Get (i, j)
   	   	   */
   	   	   
   	   	   //Use to iterate over c
   	   	   for (i = 0; i < nr1; i = i + 1)
   	   	   {
   	   	   	   //i is row
   	   	   	   //j is column
   	   	   	   //All this for c
   	   	   	   for (j = 0; j < nc2; j = j + 1)	   
   	   	   	   {
   	   	   	   	   //All this for a
   	   	   	   	   for (k = 0; k < nc1; k = k + 1)
   	   	   	   	   {
   	   	   	   	   	   entryHolderA = *(*(a + i) + k);
   	   	   	   	   	   *(holdRow + k) = entryHolderA;
   	   	   	   	   	   //printf("EntryHolderA %d ", entryHolderA);
   	   	   	   	   }
   	   	   	   	   
   	   	   	   	   //All this for b
   	   	   	   	   for (m = 0; m < nc1; m = m + 1)
   	   	   	   	   {
   	   	   	   	   	   entryHolderB = *(*(b + m) + j);
   	   	   	   	   	   *(holdColumn  + m) = entryHolderB;
   	   	   	   	   	   //printf("EntryHolderB %d ", entryHolderB);

   	   	   	   	   }
   	   	   	   
   	   	   	   	   *(*(resultingMat + i) + j) = multiplySingleMat(holdRow, holdColumn, nc1);;
   	   	   	   }
   	   	   }
   	   }
   }
   
   return resultingMat;	/* replace this line with your code */
}

int **matrixTranspose(int **a, int nr1, int cm1)
{
	int i, j, k, valueToTake;
	int **transposedMatrix = (int **) malloc(cm1 * sizeof(int *));
	
	for (i = 0; i < nr1; i = i + 1)
	{
		*(transposedMatrix + i) = (int *) malloc(nr1 * sizeof(int));
	}
	
	
	for (j = 0; j < nr1; j = j + 1)
	{
		for (k = 0; k < cm1; k = k + 1)
		{
			valueToTake = *(*(a + j) + k);
			*(*(transposedMatrix + k) + j) = valueToTake;
		}
	}
	
	return transposedMatrix;
	
	
}


/************************* END OF FILE *************************/


int main(void)
{
	int k;
	int **matR = (int **) malloc(3 * sizeof(int *));
	for (k = 0; k < 3; k = k + 1)
	{
		*(matR + k) = (int *) malloc(2 * sizeof(int));
	}
	
	initMatrix(matR, 3, 2);
	
	prtMatrix(matR, 3, 2);
	
	int **newMat = (int **) matrixTranspose(matR, 3, 2);
	prtMatrix(newMat, 2, 3);
	
}
