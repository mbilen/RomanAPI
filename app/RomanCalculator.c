/****************************************************************************************************
* Project Name			: Roman Number Calculator													*
* File Name				: Roman.c																	*
* Author/s				: Murat Bilen																*
* Source Language		: C																			*
* Compiler / Linker		: gcc version 4.6.3 - GNU ld (GNU Binutils for Ubuntu) 2.22					*
* Development Pl.		: Ubuntu 7.10 																*
* Info					:																			*
* 						  																			*
****************************************************************************************************/




#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>



#include	"RomanAPI.h"

/*********************************************************************************************/
/*										Definitions											**/
/*********************************************************************************************/
#define	ROMAN_BUFFER_SIZE	256

typedef	enum MenuOperationsE
{
	ROMAN_MENU_OPERATION_EXIT = 0x00,
	ROMAN_MENU_OPERATION_ADD,
	ROMAN_MENU_OPERATION_SUBTRACT,

	ROMAN_MENU_OPERATION_FORCE32 = 0x7FFFFFFF
}
MenuOperations;



/*********************************************************************************************/
/*										Prototypes											**/
/*********************************************************************************************/


/*		Gets Roman Number as string from user and checks it*/
void	GetRomanNumber(char * Text, char * NumberBuffer);

/*		Prints the application Menu...*/
void	PrintMenu();



#include	<math.h>



/*********************************************************************************************
* 	Function Name	: 	main
*	Purpose			: 	Application Access Point.
*					:	Select Addition or Substruction.
*					:	Enter two Roman Numbers.
* 	Parameters		: 	-
* 	Global Variables: 	-
* 	Return Values	: 	-
**********************************************************************************************/
int	main()
{
	

	char	FirstNumberBuffer[ROMAN_BUFFER_SIZE];
	char	SecondNumberBuffer[ROMAN_BUFFER_SIZE];
	char	OutputNumberBuffer[ROMAN_BUFFER_SIZE];



	int choice = 0;
	int ReturnVal;

	/*
	int i;

	for (i = 0; i < 10000; i++)
	{
		printf("%d %d\n",i,(int)log10((double)i));
		if (i % 100 == 0)
			getch();
	}
	*/

	do
	{
		PrintMenu();
		scanf("%d", &choice);

		switch (choice)
		{
			case	ROMAN_MENU_OPERATION_EXIT:		printf("Bye Mighty Bookkkeeper...\n");	break;
			case	ROMAN_MENU_OPERATION_ADD:			
												GetRomanNumber("Enter First  Number..:", FirstNumberBuffer);
												GetRomanNumber("Enter Second Number..:", SecondNumberBuffer);
												printf("Adding :: %s + %s\n", FirstNumberBuffer, SecondNumberBuffer);
												ReturnVal = RomanCalculatorAdd(OutputNumberBuffer, FirstNumberBuffer, SecondNumberBuffer, 256);
												if (ReturnVal > 0)
													printf("\n-----> Result = %s <-----", OutputNumberBuffer);
												else
													PrintErrorString(ReturnVal);

												break;

			case	ROMAN_MENU_OPERATION_SUBTRACT:											
												GetRomanNumber("Enter First  Number..:", FirstNumberBuffer);
												GetRomanNumber("Enter Second Number..:", SecondNumberBuffer);
												printf("Subtracting :: %s - %s\n", FirstNumberBuffer, SecondNumberBuffer);
												ReturnVal = RomanCalculatorSubtract(OutputNumberBuffer, FirstNumberBuffer, SecondNumberBuffer, 256);
												if (ReturnVal > 0)
													printf("\n-----> Result = %s <-----", OutputNumberBuffer);
												else
													PrintErrorString(ReturnVal);
												
												break;

			default:	printf("Unsupported entry...\n");
		}

	} 
	while (choice != ROMAN_MENU_OPERATION_EXIT);


	return 0;
}



/*********************************************************************************************
* 	Function Name	: 	PrintMenu
*	Purpose			: 	Gets Roman Number as string from user.
*					:	Trims and checks if sequencing is correct.
*					:	If it is not a valid Roman Number askes again until a valid number been entered.
*					:
* 	Parameters		: 	Text.........: Text for Displaying the number's purpose.
*					:	NumberBuffer.: Character array for number to be stored.
* 	Global Variables: 	-
* 	Return Values	: 	NumberBuffer
**********************************************************************************************/
void	GetRomanNumber(char * Text, char * NumberBuffer)
{

	int InputIsNotValid = 1;
	do
	{
		printf(Text);
		fgets(NumberBuffer, ROMAN_BUFFER_SIZE, stdin);

		/*	Skip out unnecessary chars like space Carriage Return etc...*/
		TrimString(NumberBuffer);

		if (NumberBuffer[0] != '\0')
		{
			if (CheckSequencing(NumberBuffer) < 0) /* Check if the remaining chars can make a propriate sequence */
				printf("Invalid Number Please Enter Again...\n");
			else
				InputIsNotValid = 0;
		}
	} while (InputIsNotValid);

}




/*********************************************************************************************
* 	Function Name	: 	PrintMenu
*	Purpose			: 	prints the Application menu to screen
* 	Parameters		: 	-
* 	Global Variables: 	-
* 	Return Values	: 	-
**********************************************************************************************/
void	PrintMenu()
{

	printf("\n\n\nWellcome Mighty Roman Bookkeeper...\n\n");
	printf("============	BOOKKEEPER'S MENU	======================\n");
	printf("%d.	Addition.\n",		ROMAN_MENU_OPERATION_ADD);
	printf("%d.	Subtraction.\n\n",	ROMAN_MENU_OPERATION_SUBTRACT);
	printf("%d.	EXIT\n",			ROMAN_MENU_OPERATION_EXIT);
	printf("==========================================================\n");
	printf("Your Choice..:");

}


//	EOF	----------------------------------------------------------------------------------------
