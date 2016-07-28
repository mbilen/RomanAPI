

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
	int i;
	char Buffer[256];
	int ReturnValue = 0;
	int ErrorCount = 0;

	for (i = 1; i < 10000; i++)
	{

		ConvertInt32ToRomanLetter(i, Buffer, 256);
		ReturnValue = ConvertRomanToint32(Buffer);

		if (ReturnValue != i)
		{
			printf("!!!	ERROR:	sent %8d converted to [%s] converted back to %8d\n", i, Buffer, ReturnValue);
			ErrorCount++;
		}

	}


	if (ErrorCount != 0)
	{
		printf("There were Errors...\n");
		return -1;
	}
	else
	{
		printf("All the values are converted successfully...\n");
	}



	return 0;
}
