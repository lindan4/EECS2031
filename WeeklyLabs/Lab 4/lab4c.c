#include <stdio.h>

#define MAX_SIZE 100

main() 
{

   char my_strg[ MAX_SIZE ];
   char *p = my_strg;
   char *v = my_strg;
    
   
   /********** Add your code in the below space. **********/
   /****** Do not use variable my_strg in the code. *******/
   /** You may define additional variables except arrays. */
   
   //Your code starts here
 
   /*
   
      char *p = my_strg;
      char *v = my_strg;
      
      is equivalent to 
      
      char *p, *v;
      p = my_strg;
      v = my_strg;
   */
   char temp;
   int c, pos;
   pos = 0;
   
   
   printf("Enter string to reverse: ");
   while (((c = getchar()) != EOF) && (c != '\n'))
   {
   	   *v = c;
   	   v++;
   }
   *v = '\0';
   v--;
   
   while (p < v)
   {
   	   temp = *p;
   	   *p = *v;
   	   *v = temp;
   	   
   	   p++;
   	   v--;
   }
   
   
   printf("%s\n", my_strg);
   
   
   
}
