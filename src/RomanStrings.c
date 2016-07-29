
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"RomanStrings.h"

/**
* Creates a new Dynamic String...
*
* Creates a new Dynamic String...
*
*
* @param  size:  initial Buffer Size..
* @return pointer to the newly created DynamicString.
*/

DynamicString	*	DynamicStringCreateNew(int size)
{
	DynamicString	* newString = malloc(sizeof(DynamicString));

	if (newString != NULL)
	{
		newString->Buffer = malloc(size);

		if (newString->Buffer == NULL)
		{
			free(newString);
			newString = NULL;
		}
		else
		{
			newString->BufferSize = size;
			newString->Index = 0;
			newString->Buffer[0] = '\0';
		}
	}

	return newString;
}

/**
* Grows the Dynamic String...
*
* Grows the Dynamic String...
*
*
* @param  str:  Dynamic String to grow..
* @return returns 0 on success -1 on failure.
*/
int DynamicStringGrow(DynamicString * str)
{
	int NewSize = str->BufferSize << 1;
	char * newBuffer = malloc(NewSize);

	if (newBuffer != NULL)
	{
		memcpy(newBuffer, str->Buffer, str->Index);
		str->BufferSize = NewSize;
		free(str->Buffer);
		str->Buffer = newBuffer;
		return 0;
	}

	return -1;
}



/**
* Concatenates the Dynamic string with char string...
*
* Concatenates the Dynamic string with char string...
*
*
* @param  str:  Dynamic String to be filled..
* @param  charStr:  Character string to be copied to dynamic string..
* @return returns 0 on success -1 on failure.
*/

int	DynamicStringConcatChar(DynamicString * str, char * charStr)
{
	int Size = strlen(charStr);

	if ((str->Index + Size) > str->BufferSize)
	{
		if (DynamicStringGrow(str) < 0)
			return -1;
	}

	memcpy(&str->Buffer[str->Index], charStr, Size);
	str->Index += Size;
	str->Buffer[str->Index] = '\0';

	return 0;
}


//	EOF	----------------------------------------------------------------------------------------