






#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"RomanAPI.h"





int main()
{
	int Value;

	char NullBuffer[32];
	NullBuffer[0] = '\0';

	Value = ConvertRomanToint32(NullBuffer);
	if (Value >= 0)
	{
		return -1;
	}
	Value = ConvertRomanToint32(NULL);
	if (Value >= 0)
	{
		return -1;
	}
	Value = ConvertRomanToint32(NullBuffer);
	if (Value >= 0)
	{
		return -1;
	}
	/*
	Value = ConvertRomanToint32("MMCXXXXIII");
	if (Value >= 0)
	{

	return -1;
	}
	*/
	/*
	Value = ConvertRomanToint32("MMCXXXMIII");
	if (Value >= 0)
	{
	return -1;
	}
	*/

	Value = ConvertRomanToint32("XXX");

	if (Value != 30)
	{
		printf("Wrong Conversion...\n");
		return -1;
	}

	Value = ConvertRomanToint32("CXXV");
	if (Value != 125)
	{
		printf("Wrong Conversion...\n");
		return -1;
	}

	Value = ConvertRomanToint32("CXXXIX");
	if (Value != 139)
	{
		printf("Wrong Conversion...\n");
		return -1;
	}

	Value = ConvertRomanToint32("MCCXCIX");
	if (Value != 1299)
	{
		printf("Wrong Conversion...\n");
		return -1;
	}

	return 0;

}


