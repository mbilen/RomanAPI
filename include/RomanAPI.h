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

int		RomanCalculatorAdd(OUTPUT char * Output, INPUT char * Val1, INPUT char * Val2, INPUT int OutBufferSize);
int		RomanCalculatorSubtract(OUTPUT char * Output, INPUT char * Val1, INPUT char * Val2, INPUT int OutBufferSize);

int		ConvertInt32ToRomanLetter(INPUT int Number, OUTPUT char * Buffer, INPUT int BufferSize);
int		ConvertRomanToint32(INPUT const char * RomanLetter);

/*..................................... Helpers .........................................*/

void	TrimString(INPUT_OUTPUT char * Buffer);
int		CheckSequencing(INPUT const char * RomanLetter);





#endif // !_ROMAN_API_H_INCLUDED_


//	EOF	----------------------------------------------------------------------------------------
