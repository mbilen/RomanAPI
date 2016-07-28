

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"RomanAPI.h"




/*********************************************************************************************/
/*										Global Variables									**/
/*********************************************************************************************/

int	ValueLookupTable[256];
static	int	IsTableInitialized = 0;

const char	*	RomanLetterLookupTable[3][10] =
{
	{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
	{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
	{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" }
};

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

		if (Digit == 1000)
		{
			for (i = 0; i < value; i++)
			{
				if ((cptr - Buffer) < BufferSize)
					cptr = WriteLetterToBuffer(cptr, "M", 1);
				else
				{
					DEBUG_OUT("There is no room left...");
					return -ROMAN_ERROR_CODE_BUFFER_OVERFLOW;
				}
			}
		}
		else
		{
			if ((cptr - Buffer)<BufferSize)
				cptr = WriteLetterToBuffer(cptr, RomanLetterLookupTable[LookupIndex][value], LetterSizes[value]);
			else
			{
				DEBUG_OUT("There is no room left...");
				return -ROMAN_ERROR_CODE_BUFFER_OVERFLOW;
			}
		}

		LookupIndex--;
		Digit /= 10;
	}
	if ((cptr - Buffer)<BufferSize)
		cptr = WriteLetterToBuffer(cptr, RomanLetterLookupTable[LookupIndex][Remaining], LetterSizes[Remaining]);
	else
	{
		DEBUG_OUT("There is no room left...");
		return -ROMAN_ERROR_CODE_BUFFER_OVERFLOW;
	}

	return 0;
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
	size_t LetterLength = strlen(RomanLetter);

	char *	cptr = (char*) RomanLetter;
	char *	Nextptr = cptr + 1;
	int		CharCount = 0;

	while (*Nextptr != '\0')
	{
		if (*cptr == *Nextptr)
		{
			if (*cptr == 'V' || *cptr == 'L' || *cptr == 'D')
			{
				printf("There are consequtive  '%c's, V,L and D can only be used once [%s]...\n", *cptr, RomanLetter);
				return -ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT;
			}

			if (*cptr == 'I' || *cptr == 'X' || *cptr == 'C')
			{
				CharCount = 1;
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

		cptr++;
		Nextptr = cptr + 1;
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
void	TrimString(char * Buffer)
{
	int Size = strlen(Buffer);


	//	Check if beginning of the string contains spaces...


	int i = 0;
	int j = 0;

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
			i--;
		}

		i++;
	}

	Buffer[Size] = '\0';
}




/**
* Converts Roman Number to integer...
*
* Converts Roman Number to 4 byte integer data type ...
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


	if (IsTableInitialized == 0)
	{
		InitializeValueTable();
	}



	char * cptr = (char*) RomanLetter;

	if (*cptr == '\0')
		return -ROMAN_ERROR_CODE_BUFFER_IS_NULL;

	if (CheckSequencing(RomanLetter) < 0)
	{
		return -ROMAN_ERROR_CODE_WRONG_SEQUENCE_FORMAT;
	}

	char * NextChar = cptr + 1;

	while (*NextChar != '\0' && *cptr != '\0')
	{
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
* Adds Two Roman Numbers and stores them in Output buffer ...
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
	int iVal1, iVal2, iResult;

	iVal1 = ConvertRomanToint32(Val1);

	if (iVal1 < 0)
		return iVal1;

	iVal2 = ConvertRomanToint32(Val2);

	if (iVal2 < 0)
		return iVal2;

	iResult = iVal1 + iVal2;

	if (iResult > 0)
	{
		ConvertInt32ToRomanLetter(iResult, Output, OutBufferSize);
		//printf("[%s]", Output);
		return iResult;
	}

	printf("Romans Dont have 0 so they cant code in C...\n");
	return -ROMAN_ERROR_CODE_LACK_OF_ZERO;

}



/**
* Subtracts Two Roman Numbers...
*
* Subtracts Two Roman Numbers and stores them in Output buffer ...
*
*
* @param  Output:  Resulting Roman Number in char buffer.
* @param  Val1: First Roman Number in char buffer.
* @param  Val2: Second Roman Number in char buffer.
* @param  OutBufferSize: Output Buffer Size.
* @return returns an integer value of addition for success and negative for failure.
*/
int	RomanCalculatorSubtract(char * Output, char * Val1, char * Val2, int OutBufferSize)
{
	int iVal1, iVal2, iResult;

	iVal1 = ConvertRomanToint32(Val1);

	if (iVal1 < 0)
		return iVal1;

	iVal2 = ConvertRomanToint32(Val2);

	if (iVal2 < 0)
		return iVal2;

	iResult = iVal1 - iVal2;

	if (iResult > 0)
	{
		ConvertInt32ToRomanLetter(iResult, Output, OutBufferSize);
		//printf("[%s]", Output);
		return iResult;
	}

	return -ROMAN_ERROR_CODE_LACK_OF_MINUS_VALS;
}




//	EOF	----------------------------------------------------------------------------------------

