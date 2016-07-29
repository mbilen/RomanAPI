#ifndef _ROMAN_API_H_INCLUDED_
#define	_ROMAN_API_H_INCLUDED_


/*********************************************************************************************/
/*										Definitions											**/
/*********************************************************************************************/

#ifdef _DEBUG
	#define		DEBUG_OUT(X)	printf(X)
#else
	#define		DEBUG_OUT(X)	
#endif // DEBUG

#define	INPUT
#define	OUTPUT
#define	INPUT_OUTPUT

#define		ROMAN_NUMBER_BUFFER_SIZE	1024

//typedef		int		i32;
//typedef		long	i64;

/*********************************************************************************************/
/*										Includes											**/
/*********************************************************************************************/

#include	"RomanErrors.h"
#include	"RomanStrings.h"


/*********************************************************************************************/
/*										Prototypes											**/
/*********************************************************************************************/


/*.....................................API FUNCTIONS.........................................*/

/**
* Adds Two Roman Numbers...
*
* Adds Two Roman Numbers passed with Val1 and Val2 parameters and stores them in Output buffer ...
*
*
* @param  Output:  Resulting Roman Number in char buffer.
* @param  Val1: First Roman Number in char buffer.
* @param  Val2: Second Roman Number in char buffer.
* @param  OutBufferSize: Output Buffer Size.
* @return returns an integer value of addition for success and negative for failure.
*/
int		RomanCalculatorAdd(OUTPUT char * Output, INPUT char * Val1, INPUT char * Val2, INPUT int OutBufferSize);

/**
* Subtracts Two Roman Numbers...
*
* Subtracts Two Roman Numbers passed by Val1 and Val2 parameters and stores the result in Output buffer ...
*
*
* @param  Output:  Resulting Roman Number in char buffer.
* @param  Val1:	First Roman Number in char buffer.
* @param  Val2: Second Roman Number in char buffer.
* @param  OutBufferSize: Output Buffer Size.
* @return returns an integer value of addition for success and negative for failure.
*/
int		RomanCalculatorSubtract(OUTPUT char * Output, INPUT char * Val1, INPUT char * Val2, INPUT int OutBufferSize);


/**
* Converts Int32 type to Roman Number
*
* Converts 4 byte integer value to its Roman Number equivalent.
*
*
* @param  Number: Value to be converted.
* @param  Buffer: Buffer where Roman Letters will be written.
* @param  BufferSize  : size of the buffer.
* @return returns an integer value 0 for success and negative for failure.
*/
int		ConvertInt32ToRomanLetter(INPUT int Number, OUTPUT char * Buffer, INPUT int BufferSize);

/**
* Converts Roman Number to integer...
*
* Converts Roman Number to 4 byte integer data type.
* For converting roman numbers a lookup table named ValueLookupTable is used.
* For each letter number equivalent is fetched from lookup table and summed.
*
*
* @param  RomanLetter: Roman Number in char buffer.
* @return returns an integer value of converted letter and negative for failure.
*/
int		ConvertRomanToint32(INPUT const char * RomanLetter);

/*..................................... Helpers .........................................*/
/**
* Trims The Roman Buffer string...
*
* Trims The whitespaces or other characters that is not in Roman Number set...
*
*
* @param  Buffer: Roman Number in char buffer.
* @return returns an integer value 0 for success and negative for failure.
*/
int		TrimString(INPUT_OUTPUT char * Buffer);

/**
* Checks if the Roman Numbers alphabet sequence is correct...
*
* Checks if the Roman Numbers alphabet sequence is correct...
*
*
* @param  RomanLetter: Roman Number in char buffer.
* @return returns an integer value 0 for success and negative for failure.
*/
int		CheckSequencing(INPUT const char * RomanLetter);





#endif // !_ROMAN_API_H_INCLUDED_


//	EOF	----------------------------------------------------------------------------------------
