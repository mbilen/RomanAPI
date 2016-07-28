
#include	"RomanErrors.h"
#include	<stdio.h>


/*********************************************************************************************/
/*										Global Variables									**/
/*********************************************************************************************/

const char	* RomanErrorStrings[ROMAN_ERROR_CODE_COUNT+1] =
{
	"ROMAN_ERROR_CODE_OK",
	"ROMAN_ERROR_CODE_GENERIC_ERROR",
	"ROMAN_ERROR_CODE_BUFFER_IS_NULL",
	"ROMAN_ERROR_CODE_INVALID_NUMBER",
	"ROMAN_ERROR_CODE_BUFFER_OVERFLOW",
	"ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT",
	"ROMAN_ERROR_CODE_LACK_OF_ZERO",
	"ROMAN_ERROR_CODE_LACK_OF_MINUS_VALS",
	"UNKNOWN"
};




/*********************************************************************************************
* 	Function Name	:
*	Purpose			:
* 	Parameters		: 	-
* 	Global Variables: 	-
* 	Return Values	: 	-
**********************************************************************************************/
void	PrintErrorString(int errorval)
{
	printf("RomanAPI Error : %s...\n", GetErrorString(errorval));
}


/*********************************************************************************************
* 	Function Name	:
*	Purpose			:
* 	Parameters		: 	-
* 	Global Variables: 	-
* 	Return Values	: 	-
**********************************************************************************************/
const char *	GetErrorString(int errorval)
{
	
	if (errorval < 0)
		errorval = -errorval;

	if (errorval > ROMAN_ERROR_CODE_COUNT)
		errorval = ROMAN_ERROR_CODE_COUNT;

	return RomanErrorStrings[errorval];

}

//	EOF	----------------------------------------------------------------------------------------