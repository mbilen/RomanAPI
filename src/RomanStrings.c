
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"RomanStrings.h"

/*********************************************************************************************
* 	Function Name	:
*	Purpose			:
* 	Parameters		: 	-
* 	Global Variables: 	-
* 	Return Values	: 	-
**********************************************************************************************/
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


/*********************************************************************************************
* 	Function Name	:
*	Purpose			:
* 	Parameters		: 	-
* 	Global Variables: 	-
* 	Return Values	: 	-
**********************************************************************************************/
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



/*********************************************************************************************
* 	Function Name	:
*	Purpose			:
* 	Parameters		: 	-
* 	Global Variables: 	-
* 	Return Values	: 	-
**********************************************************************************************/
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