#ifndef ROMAN_API_ERRORS_H_INCLUDED
#define	ROMAN_API_ERRORS_H_INCLUDED



typedef	enum ROMAN_EROR_CODES
{
	ROMAN_ERROR_CODE_OK = 0x00,
	ROMAN_ERROR_CODE_GENERIC_ERROR,
	ROMAN_ERROR_CODE_BUFFER_IS_NULL,
	ROMAN_ERROR_CODE_INVALID_NUMBER,
	ROMAN_ERROR_CODE_BUFFER_OVERFLOW,
	ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT,
	ROMAN_ERROR_CODE_LACK_OF_ZERO,
	ROMAN_ERROR_CODE_LACK_OF_MINUS_VALS,

	ROMAN_ERROR_CODE_COUNT,
	ROMAN_ERROR_CODE_FORCE_32 = 0x7FFFFFFF
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
void	PrintErrorString(int errorval);


/**
* Selects error codes Human readable version from RomanErrorStrings...
*
* Selects error codes Human readable version from RomanErrorStrings...
*
*
* @param  errorval:  integer representing error value..
* @return Human readable character string of error code...
*/
const char *	GetErrorString(int errorval);



#endif // !ROMAN_API_ERRORS_H_INCLUDED
