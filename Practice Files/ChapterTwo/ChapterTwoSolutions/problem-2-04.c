#include <stdio.h>
#include <stdlib.h>

/**
 * Exercise 2.4 -- Write an alternate version of squeeze(s1,s2) 
 * that deletes each character in s1 that matches any character 
 * in the string s2.
 */

void squeeze(char*,char*);
void squeezechar(char*,char);

int main(void)
{
   char* in = "foobar";
   printf("String: %s\n",in);
   squeeze(in,"aeiou");
   printf("String w/o vowels: %s\n",in);
}

void squeeze(char* s, char* srch_s)
{
   int i;

   for(i=0; srch_s[i]!='\0'; i++)
      squeezechar(s,srch_s[i]);

   return;
}

void squeezechar(char* s, char srch_c)
{
   int   i,j;

   for(i=j=0; s[i]!='\0'; i++)
   {
      if(s[i] != srch_c)
         s[j++] = s[i];
   }
   s[j] = '\0';

   return;
}
