

#include <stdio.h>

main()
{
	
	#define INCH_TO_CM 2.54
	
	float inches, centimetres;
	
	centimetres = 0;
	
	
	printf("Enter the measurement in inches>");
	
	//vairable in scanf must be preceeded with & for variables
	scanf("%f", &inches);
	while (inches != 0)
	{
		centimetres = inches * INCH_TO_CM;
		printf("\n%.2f cm\n\n", centimetres);
		printf("Enter the measurement in inches>");
		scanf("%f", &inches);
	}
	
	
}
