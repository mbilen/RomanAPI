
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



/**
* Prints out error code as human readable string...
*
* Prints out error code as human readable string...
*
*
* @param  errorval:  integer representing error value..
* @return none.
*/
void	PrintErrorString(int errorval)
{
	printf("RomanAPI Error : %s...\n", GetErrorString(errorval));
}

/**
* Selects error codes Human readable version from RomanErrorStrings...
*
* Selects error codes Human readable version from RomanErrorStrings...
*
*
* @param  errorval:  integer representing error value..
* @return Human readable character string of error code...
*/
const char *	GetErrorString(int errorval)
{
	
	if (errorval < 0)
		errorval = -errorval;

	if (errorval > ROMAN_ERROR_CODE_COUNT)
		errorval = ROMAN_ERROR_CODE_COUNT;

	return RomanErrorStrings[errorval];

}

//	EOF	----------------------------------------------------------------------------------------