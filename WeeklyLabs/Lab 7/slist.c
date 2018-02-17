/***********************************
* EECS 2031 - Lab 7		   
* Filename: slist.c  	
* Author: Last name, first name	    
* Email: Your preferred email address	 	
* Login ID: Your EECS login ID	
************************************/


#include <stdio.h>
#include <stdlib.h>


struct list {
   int data;
   struct list *next;
};




/* Display an error message. */

void prtError( char *errMsg )
{
   printf( "%s \n", errMsg );
}



/* Print the content of the list (ignoring the dummy node). */

void prtList( struct list *head )
{
   struct list *p;
   for ( p = head->next; p != NULL; p = p->next )
        printf( "%4d", p->data );
   printf( "\n");
}



/* Initialize the list. */
/* Create a dummy node to simplify insertion and deletion. */
/* After the list is created, pointers head and tail both point to the dummy node. */


void init( struct list **hptr, struct list **tptr )
{
   struct list *head;

   head = ( struct list * ) malloc( sizeof( struct list ) );
   if ( head == NULL ) {
      prtError( "Insufficient memory!" );
      exit( 1 );
   }
   head->data = -1;
   head->next = NULL;

   *tptr = *hptr = head;
}



/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/

//So we have a head pointer and a tail pointer

/* Insert a new data element d into the list. */
/* Insert at the end of the list. */
/* If a new node cannot be created, call prtError() to display 
   an error message and exit the program using exit(1). */


void insert( struct list **hptr, struct list **tptr, int d )
{

   /***** ADD YOUR CODE HERE *****/
   
   struct list **newPtr = (struct list **) malloc(sizeof(struct list *));
   
   if (newPtr == NULL)
   {
   	   prtError("Insufficient memory!");
   	   exit(1);
   }
   else
   {
   	   *newPtr = (struct list *) malloc(sizeof(struct list));
   	   if (*newPtr == NULL)
   	   {
   	   	prtError("Insufficient memory!");
   	   	exit(1);   
   	   }
   	   else
   	   {
   	   	(*newPtr)->data = d;
   	   	(*newPtr)->next = NULL;
   	   	
   	   	if ((*hptr)->next == (*tptr)->next)
   	   	{
   	   		*tptr = *newPtr;
   	   		(*hptr)->next = *tptr;
   	   	}
   	   	else
   	   	{
   	   		(*tptr)->next = *newPtr;
   	   		*tptr = *newPtr;
   	   	}	
   	   }	   
   }
}



/* Remove the first element of the list, i.e., the node right behind the dummy node. */
/* If the list is empty (i.e., containing only the dummy node), 
   call prtError() to display an error message and return -1. */
/* Otherwise, return the data (integer) of the node to be removed. */


int removeFirst( struct list **hptr, struct list **tptr )
{

   /***** ADD YOUR CODE HERE *****/
   
   int valueHolder;
   struct list *itemToRemove;
   //To check if the list is empty. Check if head and tail point to the same element
   
   if ((*hptr)->next == (*tptr)->next)
   {
   	   prtError("There are no elements to remove!");
   	   return -1;
   }
   else
   {
   	   itemToRemove = (*hptr)->next;
   	   valueHolder = itemToRemove->data;
   	   (*hptr)->next = itemToRemove->next;
   }

   return valueHolder;   /* replace this line with your code */
}


struct list *search(int d, struct list **hptr, struct list **tptr)
{
	
	struct list *theNext = (*hptr)->next;
	while (theNext != NULL)
	{
		if (theNext->data == d)
		{
			return theNext;
		}
		theNext=theNext->next;
	}
	
	return NULL;
	
	
}

int main(void)
{
	struct list **myHead = (struct list **) malloc(sizeof(struct list *));
	struct list **myTail = (struct list **) malloc(sizeof(struct list *));
	*myHead = (struct list *) malloc(sizeof(struct list));
	*myTail = (struct list *) malloc(sizeof(struct list));
	
	init(myHead, myTail);
	
	insert(myHead, myTail, 15);
	insert(myHead, myTail, 30);
	insert(myHead, myTail, 45);

	
	prtList(*myHead);
	putchar('\n');
	
	int getFirst = removeFirst(myHead, myTail);
	printf("Value that was removed: %d\n", getFirst);
	
	prtList(*myHead);
	
	//We have a pointer to a pointer
	
	struct list *getValue = (struct list *) search(30, myHead, myTail);
	printf("Searched value: %d\n", getValue->data);
	
	return 0;
	
}




