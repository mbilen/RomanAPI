

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"RomanAPI.h"




/*********************************************************************************************/
/*										Global Variables									**/
/*********************************************************************************************/


int			ValueLookupTable[256];		/*	Stores integer values of each Roman letter and 0 for others...*/
static	int	IsTableInitialized = 0;		/*	used to check if ValueLookupTable is initialized...*/

const char	*	RomanLetterLookupTable[3][10] =
{
	{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
	{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
	{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" }
};

/* string Sizes for RomanLetterLookupTable */
const int	LetterSizes[10] = { 0, 1, 2, 3, 2, 1, 2, 3, 4, 2 };








void	InitializeValueTable()
{
	
	memset(ValueLookupTable, 0, sizeof(int)* 256);

	ValueLookupTable['M'] = 1000;
	ValueLookupTable['D'] = 500;
	ValueLookupTable['C'] = 100;
	ValueLookupTable['L'] = 50;
	ValueLookupTable['X'] = 10;
	ValueLookupTable['V'] = 5;
	ValueLookupTable['I'] = 1;

	IsTableInitialized = 1;
}


/**
* Writes Roman Letters to buffer 
*
* Writes Roman Letters from lookup table to buffer. 
* 
*
* @param  buffer: buffer the letter will be written in. (previous index pointer)
* @param  letter: corresponding letter from lookup table.
* @param  size  : size of the letter from lookup table.
* @return pointer to the last index of the buffer
*/
char *	WriteLetterToBuffer(char * buffer, const char * letter, int size)
{
	if (buffer == NULL)
	{
		printf("Buffer is NULL...");
		return NULL;
	}

	if (letter == NULL)
	{
		printf("Letter arg  is NULL...");
		return NULL;
	}

	int i = 0;
	char * cptr = buffer;

	for (i = 0; i < size; i++)
	{
		*cptr = letter[i];
		cptr++;
	}

	*cptr = '\0';
	return cptr;

}


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
int		ConvertInt32ToRomanLetter(int Number, char * Buffer, int BufferSize)
{
	
	//printf("ConvertInt32ToRomanLetter::ENTER\n");

	if (Number <= 0)
	{
		printf("Unsupported Number...");
		return -ROMAN_ERROR_CODE_INVALID_NUMBER;
	}

	if (Buffer == NULL)
	{
		printf("Buffer is NULL");
		return -ROMAN_ERROR_CODE_BUFFER_IS_NULL;
	}


	int Digit;
	int	value;
	int i;
	int	LookupIndex = 3;

	int	TmpNumber = Number;
	int	Remaining;
	int	BufferIndex = 0;

	char * cptr = Buffer;

	Remaining = TmpNumber;

	Digit = 1000;
	while (Digit > 1)
	{
		value = Remaining / Digit;
		Remaining = TmpNumber % Digit;

		if (Digit == 1000)	/* SpecialCase: There is no limitation of using Ms */
		{
			for (i = 0; i < value; i++)
			{
				if (cptr != NULL)
				{
					if ((cptr - Buffer) < BufferSize)
						cptr = WriteLetterToBuffer(cptr, "M", 1);
					else
					{
						DEBUG_OUT("There is no room left...");
						return -ROMAN_ERROR_CODE_BUFFER_OVERFLOW;
					}

				}
				else
				{
					return -ROMAN_ERROR_CODE_BUFFER_OVERFLOW;
				}
			}
		}
		else
		{
			if (cptr != NULL)
			{
				if ((cptr - Buffer)<BufferSize)
					cptr = WriteLetterToBuffer(cptr, RomanLetterLookupTable[LookupIndex][value], LetterSizes[value]);
				else
				{
					DEBUG_OUT("There is no room left...");
					return -ROMAN_ERROR_CODE_BUFFER_OVERFLOW;
				}
			}
			else
			{
				return -ROMAN_ERROR_CODE_BUFFER_OVERFLOW;
			}
		}

		LookupIndex--;
		Digit /= 10;
	}
	if (cptr != NULL)
	{
		if ((cptr - Buffer)<BufferSize)
			cptr = WriteLetterToBuffer(cptr, RomanLetterLookupTable[LookupIndex][Remaining], LetterSizes[Remaining]);
		else
		{
			DEBUG_OUT("There is no room left...");
			return -ROMAN_ERROR_CODE_BUFFER_OVERFLOW;
		}
	}
	else
	{
		return -ROMAN_ERROR_CODE_BUFFER_OVERFLOW;
	}

	return 0;
}



int IsValid(char Previous, char Current)
{
	if (Current == 'M')
	{
		if (Previous == 'M' || Previous == 'C')
			return 0;
		else
			return -1;
	}
	else if (Current == 'D')
	{
		if (Previous == 'M' || Previous == 'C')
			return 0;
		else
			return -1;

	}

	else if (Current == 'C')
	{
		if (Previous == 'M' || Previous == 'D' || Previous == 'C' || Previous == 'X')
			return 0;
		else
			return -1;

	}

	else if (Current == 'L')
	{
		if (Previous == 'M' || Previous == 'D' || Previous == 'C' || Previous == 'X')
			return 0;
		else
			return -1;

	}

	else if (Current == 'X')
	{
		if (Previous == 'M' || Previous == 'D' || Previous == 'C' || Previous == 'L' || Previous == 'X')
			return 0;
		else
			return -1;

	}

	else if (Current == 'V')
	{
		if (Previous == 'M' || Previous == 'D' || Previous == 'C' || Previous == 'L' || Previous == 'X' || Previous == 'I')
			return 0;
		else
			return -1;
	}

	else if (Current == 'I')
	{
		if (Previous == 'M' || Previous == 'D' || Previous == 'C' || Previous == 'L' || Previous == 'X' || Previous == 'V' || Previous == 'I')
			return 0;
		else
			return -1;
	}
	else
	{
		return -1;
	}

	return -1;

}


/**
* Checks if the Roman Numbers alphabet sequence is correct...
*
* Checks if the Roman Numbers alphabet sequence is correct...
*
*
* @param  RomanLetter: Roman Number in char buffer.
* @return returns an integer value 0 for success and negative for failure.
*/
int		CheckSequencing(const char * RomanLetter)
{
	if (RomanLetter == NULL)
	{
		return -ROMAN_ERROR_CODE_BUFFER_IS_NULL;
	}

	if (RomanLetter[0] == '\0')
	{
		return -ROMAN_ERROR_CODE_BUFFER_IS_NULL;
	}

	size_t LetterLength = strlen(RomanLetter);

	char *	cptr = (char*) RomanLetter;
	char *	Nextptr = cptr + 1;
	char *	PreviousPtr = NULL;
	int		CharCount = 0;

	/*	We use a lookup table to find that RomanLetters corresponding number.
	*	This Lookup table is used in multiple functions and has to be initialized.
	*	therefore we check if it is initialized. if not we initialize it manually by calling InitializeValueTable()
	*/
	if (IsTableInitialized == 0)
	{
		InitializeValueTable();
	}

	while (*Nextptr != '\0')
	{
		/*	check if we have invalid letters or whitespace...*/
		if (ValueLookupTable[*cptr] == 0)
		{
			/*Call trim string to trim invalid letters...*/
			return -ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT;
		}

		/*	sequences like IVI XLX CDC are invalid lets see if we have one...*/
		if (*cptr == 'V' || *cptr == 'L' || *cptr == 'D')
		{
			if (PreviousPtr != NULL )
			{
				if (*PreviousPtr == *Nextptr)
				{
					printf("XXX\n");
					return -ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT;
				}
			}
		}

		/*	Check sequences like cannot accept more than 1 CCD IIV...*/
		if (*Nextptr == 'V' || *Nextptr == 'L' || *Nextptr == 'D')
		{
			if (PreviousPtr != NULL )
			{
				if (ValueLookupTable[*PreviousPtr] < ValueLookupTable[*cptr])
				{
					if (*PreviousPtr == *cptr)
					{
						return -ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT;
					}

				}
			}
		}

		
		/*	Check sequences like IC IV...*/
		if (PreviousPtr != NULL)
		{
			if (IsValid(*PreviousPtr, *cptr) < 0)
			{
				printf("YYY:%c%c%c\n", *PreviousPtr, *cptr, *Nextptr);
				return -ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT;
			}
		}

		/*	Check how many recurring letters we have...*/
		if (*cptr == *Nextptr)
		{
			if (*cptr == 'V' || *cptr == 'L' || *cptr == 'D')
			{
				printf("There are consequtive  '%c's, V,L and D can only be used once [%s]...\n", *cptr, RomanLetter);
				return -ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT;
			}
			/* Should not contain more than 3 consequtive I,X and Cs*/

			if (*cptr == 'I' || *cptr == 'X' || *cptr == 'C')
			{
				CharCount = 1; /*found one lets find out how many more we have*/
				while (*Nextptr == *cptr) //*Nextptr != '\0' &&
				{
					Nextptr++;
					CharCount++;
				}

				if (CharCount > 3)
				{
					printf("Cannot use more than 3 consequtive '%c's :[%s]\n", *cptr, RomanLetter);
					return -ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT;
				}

				if (*Nextptr == '\0')
					return 0;

			}
		}

		PreviousPtr = cptr;
		cptr++;
		Nextptr = cptr + 1;
	}
	/* While runs for NextPtr check the last letter before returning...*/
	if (ValueLookupTable[*cptr] == 0)
	{
		return -ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT;
	}

	return 0;
}






/**
* Trims The Roman Buffer string...
*
* Trims The whitespaces or other characters that is not in Roman Number set...
*
*
* @param  Buffer: Roman Number in char buffer.
* @return returns an integer value 0 for success and negative for failure.
*/
int	TrimString(char * Buffer)
{
	int Size;
	int i = 0;
	int j = 0;

	if (Buffer == NULL)
	{
		DEBUG_OUT("TrimString::Buffer is NULL");
		return -ROMAN_ERROR_CODE_BUFFER_IS_NULL;
	}

	if (Buffer[0] == '\0')
	{
		DEBUG_OUT("TrimString::Empty String Passed...");
		return -ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT;
	}

	Size = strlen(Buffer);

	/*	We use a lookup table to find that RomanLetters corresponding number.
	*	This Lookup table is used in multiple functions and has to be initialized.
	*	therefore we check if it is initialized. if not we initialize it manually by calling InitializeValueTable()
	*/
	if (IsTableInitialized == 0)
	{
		InitializeValueTable();
	}

	i = 0;
	while (i<Size)
	{
		if (ValueLookupTable[Buffer[i]] == 0)
		{

			for (j = i; j < Size - 1; j++)
			{
				Buffer[j] = Buffer[j + 1];
			}

			Size--;
			i--; /* (i+1)th element is now (i)th element check to check ith element again decrease i..*/
		}

		i++;
	}

	Buffer[Size] = '\0';
	return 0;
}




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

int		ConvertRomanToint32(const char * RomanLetter)
{
	if (RomanLetter == NULL)
	{
		DEBUG_OUT("Argument RomanLetter is NULL...\n");
		return -ROMAN_ERROR_CODE_BUFFER_IS_NULL;
	}


	int i = 0;
	int Total = 0;

	/*	We use a lookup table to find that RomanLetters corresponding number. 
	*	This Lookup table is used in multiple functions and has to be initialized.
	*	therefore we check if it is initialized. if not we initialize it manually by calling InitializeValueTable()
	*/
	if (IsTableInitialized == 0)
	{
		InitializeValueTable();
	}



	char * cptr = (char*) RomanLetter;

	if (*cptr == '\0')
		return -ROMAN_ERROR_CODE_BUFFER_IS_NULL;

	/*	Lets see if this Roman Number is a valid Roman Number.
	*	
	*/
	if (CheckSequencing(RomanLetter) < 0)
	{
		return -ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT;
	}

	char * NextChar = cptr + 1;

	while (*NextChar != '\0' && *cptr != '\0')
	{
		/*	Roman numbers can be represented with pairs, which preceeding letter is less than current such as IV XC
		*	therefore first we check if we have to continue with pairs or letter alone.
		*/
		if (ValueLookupTable[*cptr] < ValueLookupTable[*NextChar])
		{
			Total += ValueLookupTable[*NextChar] - ValueLookupTable[*cptr];
			cptr += 2;
			NextChar += 2;
		}
		else
		{
			Total += ValueLookupTable[*cptr];
			cptr++;
			NextChar++;
		}
	}
	/* Most of the time the while loop will quit when NextChar reaches the end of the buffer
	* so this leaves one more letter to count on.
	*/
	if (*cptr != '\0')
	{
		Total += ValueLookupTable[*cptr];
	}

	//printf("Total = %d",Total);
	return Total;

}



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
int	RomanCalculatorAdd(char * Output, char * Val1, char * Val2, int OutBufferSize)
{
	if (Output == NULL)
		return -ROMAN_ERROR_CODE_BUFFER_IS_NULL;

	/*We dont need to check Val1 and Val2 if they are null...*/
	/* they will be checked at ConvertRomanToint32*/

	int iVal1, iVal2, iResult,ReturnValue;

	iVal1 = ConvertRomanToint32(Val1);

	if (iVal1 < 0)
		return iVal1;

	iVal2 = ConvertRomanToint32(Val2);

	if (iVal2 < 0)
		return iVal2;

	iResult = iVal1 + iVal2;

	if (iResult > 0)
	{
		ReturnValue = ConvertInt32ToRomanLetter(iResult, Output, OutBufferSize);

		/*	Check if we have a conversion error...*/
		if (ReturnValue < 0)
			return ReturnValue;

		//printf("[%s]", Output);
		return iResult;
	}

	printf("Romans Dont have 0 so they cant code in C...\n");
	return -ROMAN_ERROR_CODE_LACK_OF_ZERO;

}



/**
* Subtracts Two Roman Numbers...
*
* Subtracts Two Roman Numbers passed by Val1 and Val2 parameters
* and stores the result in Output buffer ...
*
*
* @param  Output:  Resulting Roman Number in char buffer.
* @param  Val1:	First Roman Number in char buffer.
* @param  Val2: Second Roman Number in char buffer.
* @param  OutBufferSize: Output Buffer Size.
* @return returns an integer value of addition for success and negative for failure.
*/
int	RomanCalculatorSubtract(char * Output, char * Val1, char * Val2, int OutBufferSize)
{
	int iVal1, iVal2, iResult,ReturnValue;

	if (Output == NULL)
		return -ROMAN_ERROR_CODE_BUFFER_IS_NULL;

	/*We dont need to check Val1 and Val2 if they are null...*/
	/* they will be checked at ConvertRomanToint32*/


	iVal1 = ConvertRomanToint32(Val1);

	if (iVal1 < 0)
		return iVal1;

	iVal2 = ConvertRomanToint32(Val2);

	if (iVal2 < 0)
		return iVal2;

	iResult = iVal1 - iVal2;

	if (iResult > 0)
	{
		ReturnValue = ConvertInt32ToRomanLetter(iResult, Output, OutBufferSize);

		/*	Check if we have a conversion error...*/
		if (ReturnValue < 0)
			return ReturnValue;

		return iResult;
	}

	return -ROMAN_ERROR_CODE_LACK_OF_MINUS_VALS;
}




//	EOF	----------------------------------------------------------------------------------------

