

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"RomanAPI.h"



int main()
{


	char Buffer[256];

	//TestValues();

	ConvertInt32ToRomanLetter(1234, Buffer, 256);	
	printf("[%s]", Buffer);	
		
	if (strcmp(Buffer, "1234") != 0) 
	{ 
		printf("ERROR\n"); 
		return -1; 
	}



	ConvertInt32ToRomanLetter(5678, Buffer, 256);	
	printf("[%s]", Buffer);

	if (strcmp(Buffer, "5678") != 0)
	{
		printf("ERROR\n");
		return -1;
	}
	
	

	ConvertInt32ToRomanLetter(9111, Buffer, 256);
	printf("[%s]", Buffer);

	if (strcmp(Buffer, "9111") != 0)
	{
		printf("ERROR\n");
		return -1;
	}
	

	
	ConvertInt32ToRomanLetter(13579, Buffer, 256);	
	printf("[%s]", Buffer);

	if (strcmp(Buffer, "13579") != 0)
	{
		printf("ERROR\n");
		return -1;
	}
	
	
	
	ConvertInt32ToRomanLetter(2468, Buffer, 256);	
	printf("[%s]", Buffer);

	if (strcmp(Buffer, "2468") != 0)
	{
		printf("ERROR\n");
		return -1;
	}





	return 0;
}
