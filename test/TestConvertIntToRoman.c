

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"RomanAPI.h"



int main()
{

	char Buffer[256];
	char NullBuffer[32];
	NullBuffer[0] = '\0';

	printf("NULL");
	if (ConvertInt32ToRomanLetter(1234, NULL, 256) >= 0)
	{
		return -1;
	}
	printf("NULL Buffer");
	/*
	if (ConvertInt32ToRomanLetter(1234, NullBuffer, 256) != 0)
	{
	return -1;
	}
	*/
	printf("1");
	if (ConvertInt32ToRomanLetter(0, NullBuffer, 256) >= 0)
	{
		return -1;
	}
	printf("1");
	if (ConvertInt32ToRomanLetter(-123, NullBuffer, 256) >= 0)
	{
		return -1;
	}



	ConvertInt32ToRomanLetter(1234, Buffer, 256);
	printf("[%s]", Buffer);

	if (strcmp(Buffer, "MCCXXXIV") != 0)
	{
		printf("ERROR [%s] : should be 1234\n", Buffer);
		return -1;
	}

	ConvertInt32ToRomanLetter(5678, Buffer, 256);
	printf("[%s]", Buffer);

	if (strcmp(Buffer, "MMMMMDCLXXVIII") != 0)
	{
		printf("ERROR\n");
		return -1;
	}

	ConvertInt32ToRomanLetter(9111, Buffer, 256);
	printf("[%s]", Buffer);

	if (strcmp(Buffer, "MMMMMMMMMCXI") != 0)
	{
		printf("ERROR\n");
		return -1;
	}

	ConvertInt32ToRomanLetter(13579, Buffer, 256);
	printf("[%s]", Buffer);

	if (strcmp(Buffer, "MMMMMMMMMMMMMDLXXIX") != 0)
	{
		printf("ERROR\n");
		return -1;
	}

	ConvertInt32ToRomanLetter(2468, Buffer, 256);
	printf("[%s]", Buffer);

	if (strcmp(Buffer, "MMCDLXVIII") != 0)
	{
		printf("ERROR\n");
		return -1;
	}

	return 0;
}
