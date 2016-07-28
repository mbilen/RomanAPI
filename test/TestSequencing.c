

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
	char NullBuffer[32];
	NullBuffer[0] = '\0';
/*
	if (CheckSequencing(NULL) >= 0)
	{
		printf("Should not pass...");
		return -1;
	}

	if (CheckSequencing(NullBuffer) >= 0)
	{
		printf("Should not pass...");
		return -1;
	}
*/
//----------------------------------------------

	if (CheckSequencing("MCLXXXX") >= 0)
	{
		printf("Should not pass...");
		return -1;
	}

	if (CheckSequencing("MCCCCXXX") >= 0)
	{
		printf("Should not pass...");
		return -1;
	}

	if (CheckSequencing("MCLLXXX") >= 0)
	{
		printf("Should not pass...");
		return -1;
	}


	if (CheckSequencing("MCLXXXIIII") >= 0)
	{
		printf("Should not pass...");
		return -1;
	}

	return 0;
}



