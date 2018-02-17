/***********************************
* EECS2031 - Assignment 1
* Filename: poly.c 
* Author: Thillanayagam, Lindan
* Email: lindan4@my.yorku.ca
* Login ID: lindan4
************************************/

#include "poly.h"


#define TEN 10
#define MAX_HOLDER_SIZE 500




int numberLength(int n);
char *numberToArray(int p);
double toPower(double a, double b);
int getGreatestPower(int t[]);
/* 
  Initialize all coefficients and exponents of the polynomial to zero.
 */
void init_polynom( int coeff[ ], int exp[ ] )
{

   /* ADD YOUR CODE HERE */
   //The arrays in the parameter are, in a way, already declared. Thus.
   int i;
 
   
   for (i = 0; i < ASIZE; i = i + 1)
   {
   	   coeff[i] = 0;
   	   exp[i] = 0;
   }

   
}  /* end init_polynom */


/*
  Get inputs from user using scanf() and store them in the polynomial.
 */
void get_polynom( int coeff[ ], int exp[ ] )
{
	//ASSUME ALL INPUTS ARE VALID AND NO ERROR CHECKING IS REQUIRED. SO IN THAT CASE IF THE USER INPUTS MORE TERMS THAN THE AMOUNT
	//THAN HE/SHE STATED, THEN IT IS HIS/HER FAULT. THE FIRST NUMBER OUT OF PLACE WILL BE READ AS THE NUMBER OF TERMS
	int singleCo, singleExp, termCount, count = 0; 
	int maxExp, tempSum, tempPos = 0;
	int i, j;
	static int zeroCoeff[ASIZE], zeroExp[ASIZE]; 
	init_polynom(zeroCoeff, zeroExp);
	//init_polynom(coeff, exp);
	
	//printf("Enter the number of terms: ");
	scanf("%d", &termCount);
	
	//printf("Term count: %d\n", termCount);
	
	if (termCount > 0)
	{
		//printf("\nEnter a coefficient: ");
		scanf("%d", &singleCo);
		coeff[count] = singleCo;
		//termsIncl = termsIncl + 1;

	
		//printf("\nEnter an exponent: ");
		scanf("%d", &singleExp);
		exp[count] = singleExp;
		count++;
	
		while ((count < termCount) && (count < ASIZE))
		{
			//printf("\nEnter a coefficient: ");
			scanf("%d", &singleCo);
			coeff[count] = singleCo;
			//termsIncl = termsIncl + 1;

	
			//printf("\nEnter an exponent: ");
			scanf("%d", &singleExp);
			exp[count] = singleExp;
			count++;
		//termsIncl = termsIncl + 1;
		}
		
		//THE TERMS ARE INPUT IN THE DECREASING ORDER OF THEIR EXPONENTS
		
		maxExp = getGreatestPower(exp);
	
		for (i = maxExp; i >= 0; i = i - 1)
		{
			tempSum = 0;
			for (j = 0; j < ASIZE; j = j + 1)
			{
				if (exp[j] == i)
				{
					tempSum = tempSum + coeff[j];
				}
		
			}
		
			if (tempSum != 0)
			{
				zeroCoeff[tempPos] = tempSum;
				zeroExp[tempPos] = i;
				tempPos++;
			}
		}
		init_polynom(coeff, exp);
	
		for (i = 0; i < ASIZE; i = i + 1)
		{
			coeff[i] = zeroCoeff[i];
			exp[i] = zeroExp[i];
		}
		
		
		
	}
	else
	{
		init_polynom(coeff, exp);
	}
	
}  /* end get_polynom */


/*
  Convert the polynomial to a string s.
 */
void polynom_to_string( int coeff[ ], int exp[ ], char s[ ] )
{
   
   /* ADD YOUR CODE HERE */

   	int i, j, coefficientConstant, exponentConstant;
	int counter = 0;
	int theSum = 0;
	char *expo, *numToArray;	
	
	for (i = 0; i < ASIZE; i = i + 1)
	{
		coefficientConstant = coeff[i];
		exponentConstant = exp[i];
		theSum = theSum + coefficientConstant;
		
		
		if (coefficientConstant < -1)
		{
			s[counter] = '-';
			counter = counter + 1;
			numToArray = (char *) numberToArray(-coefficientConstant);
			for (j = 0;  *(numToArray + j) != '\0'; j = j + 1)
			{
				s[counter] = *(numToArray + j);
				counter = counter + 1;
			}
			expo = (char *) numberToArray(exponentConstant);
			if (exponentConstant != 0)
			{
				s[counter] = 'x';
				counter = counter + 1;
				if (exponentConstant != 1)
				{
					s[counter] = '^';
					counter = counter + 1;
			
					for (j = 0; *(expo + j) != '\0'; j = j + 1)
					{
						s[counter] = *(expo + j);
						counter = counter + 1;
					}
				}
			}
		}
		else if (coefficientConstant == -1)
		{
			s[counter] = '-';
			counter = counter + 1;
						
			expo = (char *) numberToArray(exponentConstant);

			if (exponentConstant == 0)
			{
				s[counter] = '1';
				counter = counter + 1;
			}
			else
			{
				s[counter] = 'x';
				counter = counter + 1;
				if (exponentConstant != 1)
				{
					s[counter] = '^';
					counter = counter + 1;
					for (j = 0; *(expo + j) != '\0'; j = j + 1)
					{
						s[counter] = *(expo + j);
						counter = counter + 1;
					}
					
				}
			}
		}
		else if (coefficientConstant == 0)
		{
			
		}
		else if (coefficientConstant == 1)
		{
			if (counter != 0)
			{
				s[counter] = '+';
				counter = counter + 1;
			}
			expo = (char *) numberToArray(exponentConstant);
			


			if (exponentConstant == 0)
			{
				s[counter] = '1';
				counter = counter + 1;
			}
			else
			{
				s[counter] = 'x';
				counter = counter + 1;
				
				if (exponentConstant != 1)
				{
					s[counter] = '^';
					counter = counter + 1;
			
					for (j = 0; *(expo + j) != '\0'; j = j + 1)
					{
						s[counter] = *(expo + j);
						counter = counter + 1;
					}
				}	
			}
		}
		else
		{
			if (counter != 0)
			{
				s[counter] = '+';
				counter = counter + 1;
			}
			numToArray = (char *) numberToArray(coefficientConstant);

			for (j = 0;  *(numToArray + j) != '\0'; j = j + 1)
			{
				s[counter] = *(numToArray + j);
				counter = counter + 1;
			}
			expo = (char *) numberToArray(exponentConstant);
			

			
			if (exponentConstant != 0)
			{
				s[counter] = 'x';
				counter = counter + 1;
				if (exponentConstant != 1)
				{
					s[counter] = '^';
					counter = counter + 1;
			
					for (j = 0; *(expo + j) != '\0'; j = j + 1)
					{
						s[counter] = *(expo + j);
						counter = counter + 1;
					}	
				}	
			}
		}
	}
	
	if (theSum == 0)
	{
		s[counter] = '0';
		counter++;
	}
	s[counter] = '\0';
	
	//printf("%s\n",(theSum != 0) ? s : "0");
}  /* end polynom_to_string */



/*
  Evaluate the polynomial for the value of x and store the result p(x) in variable result.
 */
void eval_polynom( int coeff[ ], int exp[ ], double x, double *result )
{

   /* ADD YOUR CODE HERE */
   	int p;
	double singleCo, singleExp;
	double outcome = 0;
	
	
	for (p = 0; p < ASIZE; p = p + 1)
	{
		singleCo = (double) coeff[p];
		singleExp = (double) exp[p];
		outcome = outcome + (singleCo * toPower(x, singleExp));
		//printf("coeff: %lf, exp: %lf, x: %lf, outcome: %lf\n", singleCo, singleExp, x, outcome);
	}
	*result = outcome;

}  /* end eval_polynom */



/*
  Add two polynomials and the result is stored in the first polynomial (arrays co1[] and ex1[]).
 */
void add_polynom( int co1[ ], int ex1[ ], int co2[ ], int ex2[ ] )
{

   /* ADD YOUR CODE HERE */
   
   	static int tempCo[ASIZE], tempExp[ASIZE];   
   	
   	int maxExp, i, j, tempSum = 0;
   	int tempPos = 0;
	
	init_polynom(tempCo, tempExp);
	
	//printf("%d", tempCo[0]);
	
	maxExp = (getGreatestPower(ex1) < getGreatestPower(ex2)) ? getGreatestPower(ex2) : getGreatestPower(ex1);
	
	for (i = maxExp; i >= 0; i = i - 1)
	{
		tempSum = 0;
		for (j = 0; j < ASIZE; j = j + 1)
		{
			if (ex1[j] == i)
			{
				tempSum = tempSum + co1[j];
			}
			
			if (ex2[j] == i)
			{
				tempSum = tempSum + co2[j];
			}
		
		}
		
		//co1 9 -5 2 7 6
		//ex1 4 5 7 6
		if (tempSum != 0)
		{
			tempCo[tempPos] = tempSum;
			tempExp[tempPos] = i;
			tempPos++;
		}
	}
	init_polynom(co1, ex1);
	
	for (i = 0; i < ASIZE; i = i + 1)
	{
		co1[i] = tempCo[i];
		ex1[i] = tempExp[i];
	}

}  /* end add_ polynom */

int numberLength(int n)
{
	int counter = 0;
	int tenStart = 1;
	if (n == 0)
	{
		return 1;
	}
	
	while ((n / tenStart) != 0)
	{
		counter = counter + 1;
		tenStart = tenStart * TEN;
	}
	return counter;
}

char *numberToArray(int p)
{
	static char collectorArray[MAX_HOLDER_SIZE];
	int numberSize = numberLength(p);
	int powerTo, digitHold = 0;
	int i;
	int number = p;
	
	powerTo = toPower(TEN, numberSize - 1);
	
	for (i = 0; i < numberSize; i = i + 1)
	{
		digitHold = number / powerTo;
		collectorArray[i] = digitHold + '0';
		number = number % powerTo;
		powerTo = powerTo / TEN;
	}
	
	collectorArray[i] = '\0';
	return collectorArray;
}

double toPower(double a, double b)
{
	if (b < 0)
	{
		return (1 / a) * toPower(a, b + 1);
	}
	else if (b == 0)
	{
		return 1;
	}
	else
	{
		return a * toPower(a, b - 1);
	}
}

int getGreatestPower(int t[])
{
	int k, hold;
	int max = 0;
	
	for (k = 0; k < ASIZE; k = k + 1)
	{
		hold = t[k];
		max = (hold > max) ? hold : max;
	}
	
	return max;
}


/************************** END OF FILE ***************************/





