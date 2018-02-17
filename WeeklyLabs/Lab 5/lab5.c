/***********************************
* EECS 2031 - Lab 5		   
* Filename: lab5.c	  	
* Author: Last name, first name	    
* Email: Your preferred email address	 	
* Login ID: Your EECS login ID	
************************************/


#include <stdio.h>
#include <stdlib.h>

/* Definition of structure extendableArray */

struct extendableArray {
   int *arr;	/* array of integers */
   int size;	/* number of elements currently stored in the array */
   int capacity;/* capacity of the currently allocated array */
};



/* Initializes the extendable array */

struct extendableArray *initArr()
{
   struct extendableArray *a = ( struct extendableArray * ) malloc( sizeof( struct extendableArray ) );
   if( !a ) {
	printf( "Insufficient memory!" );
	exit( 1 );
   }
   a->capacity = 4;		/* initial capacity */
   a->arr = ( int * ) malloc( a->capacity * sizeof( int ));
   if( !a->arr ) {
	printf( "Insufficient memory!" );
	exit( 1) ;
   }
   a->size = 0;			/* no element added to the array yet */
   return a;
}



/* Returns the size of the array */

int arrSize( struct extendableArray *a ) 
{
	return( a->size );
}



/* Returns the capacity of the array. */

int arrCapacity( struct extendableArray *a ) 
{
	return( a->capacity );
}



/* Returns true (1) if the array is empty, and false (0) otherwise. */

int isEmpty( struct extendableArray *a) 
{
	return( a->size == 0 );
}



/* Returns true (1) if the array is full, and false (0) otherwise. */

int isFull( struct extendableArray *a ) 
{
	return( a->size ==  a->capacity );
}



/* Prints the error message msg. */

void printErr( char *msg )
{
   printf( "\n%s\n", msg );
}



/* Prints the content of the array. */

void printArray( struct extendableArray *a )
{
   int i;

   if( isEmpty( a ) ) 
	printErr( "printArray(): empty array." );
    
   for( i = 0; i < a->size; i++)
	printf( "%3d ",  a->arr[i] );

   printf("\n");
}




/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/

/* Inserts integer d at the rear of the array, right behind the last element. */
/* Assume all inputs are non-negative integers. */

void insertLast( struct extendableArray *a, int d ) 
{

	/* Add your implementation here */
	
	//Get # elements in array
	int arraySize = arrSize(a);
	int *arrAccess = a->arr;
	int lastInteger, i;
	int *replacementArray, replacementCapacity;
	const int TWO = 2;
	
	//Based on the main file, insert then change the capacity
	if (a == NULL)
	{
		printErr("Insufficient memory.");
	}
	else
	{
		
		a->size = a->size + 1;

		*(arrAccess + (a->size) - 1) = d;
		

	}
	if (a->size > a->capacity)
	{
		replacementCapacity = a->capacity * TWO;
		//printf("Replacement capacity: %d\n", replacementCapacity);
		replacementArray = (int *) malloc(sizeof(int) * replacementCapacity);
		
		for (i = 0; i < a->size; i = i + 1)
		{
			*(replacementArray + i) = *(arrAccess + i);
		}
		a->capacity = replacementCapacity;
		a->arr = replacementArray;
			
			//free the old array
		free(arrAccess);
	}
	

}



/* Removes and returns the last element of the array (the element that was inserted last). */
/* If the array is empty, call printErr() to display a message and return -1. */

int removeLast( struct extendableArray *a )
{

	/* Add your implementation here */
	int lastElement, newCapacity, i;
	int *arrayA, *newArray;
	const int FOUR = 4;
	const int TWO = 2;
	
	if (a == NULL || (a->size == 0) || (a->capacity == 0))
	{
		printErr("Array has not been initialized");
		return -1;
	}
	else
	{
		arrayA = a->arr;
		
		//Get element to be removed
		lastElement = *(arrayA + (a->size) - 1);
		
		a->size = a->size - 1;

		*(arrayA + a->size) = 0;
		
		if (a->size < (a->capacity / FOUR))
		{
			newCapacity = a->capacity / TWO;
			newCapacity = (newCapacity < FOUR) ? FOUR : newCapacity;
			newArray = (int *) malloc(sizeof(int) * newCapacity);
			for (i = 0; i < a->size; i = i + 1)
			{
				*(newArray + i) = *(arrayA + i);	
			}
			a->capacity = newCapacity;
			a->arr = newArray;
			
			free(arrayA);
		}
		
	}
	return lastElement;  /* replace this line with your own code */
}


/************************** END OF FILE ***************************/

