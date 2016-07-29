#ifndef _ROMAN_STRINGS_H_INCLUDED_
#define	_ROMAN_STRINGS_H_INCLUDED_






typedef	struct DynamicString
{
	char *	Buffer;
	int		BufferSize;
	int		Index;
}
DynamicString;



/**
* Creates a new Dynamic String...
*
* Creates a new Dynamic String...
*
*
* @param  size:  initial Buffer Size..
* @return pointer to the newly created DynamicString.
*/

DynamicString	*	DynamicStringCreateNew(int size);

/**
* Grows the Dynamic String...
*
* Grows the Dynamic String...
*
*
* @param  str:  Dynamic String to grow..
* @return returns 0 on success -1 on failure.
*/
int DynamicStringGrow(DynamicString * str);

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

int	DynamicStringConcatChar(DynamicString * str, char * charStr);



#endif // !_ROMAN_STRINGS_H_INCLUDED_

//	EOF	----------------------------------------------------------------------------------------
