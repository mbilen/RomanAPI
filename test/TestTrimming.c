

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
	char str1[] = " XXXIV ";
	char str2[] = "ABCDEFGH";

	TrimString(str1);
	if (strcmp(str1, "XXXIV") != 0)
	{
		printf("Error Trimming String...\n");
		return -1;
	}

	TrimString(str2);
	if (strcmp(str2, "CD") != 0)
	{
		printf("Error Trimming String...\n");
		return -1;
	}

	return 0;

}
