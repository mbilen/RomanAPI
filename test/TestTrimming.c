

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"RomanAPI.h"



/*********************************************************************************************
* 	Function Name	:
*	Purpose			:
* 	Parameters		: 	-
* 	Global Variables: 	-
* 	Return Values	: 	-
**********************************************************************************************/
int		main()
{
	int ReturnValue = 0;
	char str1[] = " XXXIV ";
	char str2[] = "ABCDEFGH";

	char NullBuffer[32];
	NullBuffer[0] = '\0';

	ReturnValue = TrimString(NULL);
	if (ReturnValue >= 0)
	{
		printf("Should Not Accept NULL String...\n");
		return -1;
	}

	ReturnValue = TrimString(NullBuffer);
	if (ReturnValue >= 0)
	{
		printf("Should Not Accept NULL String...\n");
		return -1;
	}



	ReturnValue = TrimString(str1);
	if (ReturnValue < 0)
	{
		return -1;
	}

	if (strcmp(str1, "XXXIV") != 0)
	{
		printf("Error Trimming String...\n");
		return -1;
	}

	ReturnValue = TrimString(str2);
	if (ReturnValue < 0)
	{
		return -1;
	}
	if (strcmp(str2, "CD") != 0)
	{
		printf("Error Trimming String...\n");
		return -1;
	}

	return 0;

}
