
#include <stdio.h>

main()
{
	/*Declare variables in main*/
	
	/*Don't type 'int' for every variable*/
	float fahrenheit, celsius;
	
	#define LOWER 0
	#define UPPER 200
	#define STEP 20
	
	fahrenheit = 0;
	
	printf("Fahrenheit\tCelsius\n");
	while (fahrenheit <= UPPER)
	{
		celsius = 5 * (fahrenheit - 32) / 9;
		printf("%3.0f %16.1f\n", fahrenheit, celsius);
		fahrenheit = fahrenheit + STEP;
	}

	
}
