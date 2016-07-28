






#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"RomanAPI.h"





int main()
{
	int Value;

	char NullBuffer[32];
	NullBuffer[0] = '\0';


	Value = ConvertRomanToint32("");
	printf("%d", Value);
	Value = ConvertRomanToint32(NULL);
	printf("%d", Value);
	Value = ConvertRomanToint32(NullBuffer);
	printf("%d", Value);
	Value = ConvertRomanToint32("MMCXXXXIII");
	printf("%d", Value);
	Value = ConvertRomanToint32("MMCXXXMIII");
	printf("%d", Value);

	
	



	Value = ConvertRomanToint32("XXX");			printf("Should be 30\n");

	if (Value != 30)
	{
		printf("Wrong Conversion...\n");
		return -1;
	}

	Value = ConvertRomanToint32("CXXV");		printf("Should be 125\n");
	if (Value != 125)
	{
		printf("Wrong Conversion...\n");
		return -1;
	}

	Value = ConvertRomanToint32("CXXXIX");		printf("Should be 139");
	if (Value != 139)
	{
		printf("Wrong Conversion...\n");
		return -1;
	}

	Value = ConvertRomanToint32("MCCXCIX");		printf("Should be 1299");
	if (Value != 1299)
	{
		printf("Wrong Conversion...\n");
		return -1;
	}


return 0;
}


