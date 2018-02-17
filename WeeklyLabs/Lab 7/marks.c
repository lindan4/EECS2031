/***********************************
* EECS 2031 - Lab 7		   
* Filename: marks.c  	
* Author: Last name, first name	    
* Email: Your preferred email address	 	
* Login ID: Your EECS login ID	
************************************/

#include <stdio.h>
#include <stdlib.h>


  /*****  YOU MAY ADD YOUR OWN FUNCTION(S) HERE.  *****/
  
int getLength(char *s)
{
	int length = 0;
	while(*s != '\0')
	{
		s++;
		length++;
	}
	return length;
}

int main( int argc, char *argv[] )
{

  /*****************************************/
  /***** ADD YOUR CODE BELOW THIS LINE *****/
  
  FILE *fin, *fout;
  
  char firstName[100], lastName[100];
  
  const int TWO = 2;
  int assignmentOneM, assignmentTwoM;
  
  float mAvg = 0;
  
  if (argc <= 2)
  {
  	  printf("Usage: marks [input_file] [output_file]\n");
  }
  else if (argc > 5)
  {
    	  printf("Usage: marks [input_file] [output_file]\n");	  
  }
  else
  {
  	  if (getLength(*(argv + 1)) >= 30 || getLength(*(argv + 2)) >= 30)
  	  {
  	  	  printf("Each filename must be less than 30 characters long.\n");
  	  }
  	  else
  	  {
  	  	  fin = (FILE *) fopen(*(argv + 1), "r");
  	  	  fout = (FILE *) fopen(*(argv + 2), "w");
  	  	  
  	  	  //It is not checking for reading errors??
  	  	  if (fin == NULL)
  	  	  {
  	  	  	 printf("Cannot open file %s for reading.\n", *(argv + 1));
  	  	  	 exit(1);

  	  	  }
  	  	  	  
  	  	  if (fout == NULL)
  	  	  {
  	  	  	 printf("Cannot open file %s for writing.\n", *(argv + 2));
  	  	 	 exit(1);
  	  	  }
  	  	  
  	  	  
  	  	   while ((fscanf(fin, "%s %s %d %d", firstName, lastName, &assignmentOneM, &assignmentTwoM)) != EOF)
  	  	   {
  	 	  	  mAvg = (float) (assignmentOneM + assignmentTwoM) / (float) TWO;
   	  	  	  fprintf(fout, "%s %s %d %d %.1f\n", firstName, lastName, assignmentOneM, assignmentTwoM, mAvg);
  	  	   }
  	  	   fclose(fin);
  	  	   fclose(fout);
  	  }  
  }



  /***** ADD YOUR CODE ABOVE THIS LINE *****/
  /*****************************************/
  return 0;
}  /* end main */


