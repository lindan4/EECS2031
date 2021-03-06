#include <stdio.h>
#include <stdlib.h>

#define TYPE_YEARS 2
#define MONTHS 13

static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
{0, 31, 29, 31, 30, 31, 30, 31, 31, 31, 31, 30, 31}
};


int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
	int a, b, c, f, dayOfTheYear;
	
	int *d, *e;
	d = (int *) malloc(sizeof(int));
	e = (int *) malloc(sizeof(int));
	
	printf("Enter year, month, and day (yyyy mm dd): ");
	scanf("%d %d %d", &a, &b, &c);
	
	dayOfTheYear = day_of_year(a, b, c);
	printf("\nDay of the year: %d\n", dayOfTheYear);
	
	printf("\nEnter day of year: ");
	scanf("%d", &f);
	month_day(a, f, d, e);
	
	printf("\nDay of month: %d %d\n", *d, *e);
	
	return 0;
}


//Rewrite with pointers instead of indexing
int day_of_year(int year, int month, int day)
{
	int i, leap;
	char *p;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	
	//Have this point to the first month
	p = &daytab[leap][0];

	
	if (year >= 0 && month >= 0 && month <= 12)
	{
		//Rewrite this
		if (*(p + month) >= day)
		{
			for (i = 1; i <= month; i = i + 1)
			{
				//day += daytab[leap][i];
				day += *p;
				++p;
			}             
			return day;
		}
		else
		{
			return 0;
		}
		
	}
	else
	{
		return 0;
	}
	
	
}
//sets from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	
	char *p;
	
	//Gain access to the 0th element
	p = &daytab[leap][0];
	
	if (year >= 0 && yearday >= 0 && ((yearday <= 365 && !leap) || (yearday <= 366) && leap))
	{
		for (i = 1; yearday > *(p + i); i = i + 1)
		{
			yearday -= *(p + i);
		}
		*pmonth = i;
		*pday = yearday;
	}
	else
	{
		*pmonth = 0;
		*pday = 0;
	}
}
