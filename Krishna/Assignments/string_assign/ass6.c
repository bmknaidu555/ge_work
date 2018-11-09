#include <stdio.h>
#include <stdlib.h> 
#include "lib/f_strlen.c"
#include "lib/f_sappend.c"

#define BUFFER 50

//  paetial Executed



int main()
{
	
	//To catch the result returned by string compare function.
	int result;    

	// Source buffer
	char* str1 = malloc( BUFFER );
	char* str2 = malloc( BUFFER);
	

	//Reading string 1 from user
	printf ("\n Please enter The input String   :  ");
	fgets ( str1, BUFFER, stdin );


	//Validation : 1
	if (*str1 == '\n' ||f_strlen(str1) == 0 || *str1 == '\0' )
	{
		printf (" Input Should not be empty! \n");
		return 0;
	}	

		
	__fpurge (stdin);			//   Clearing the Buffer4

														
	printf ("\n Please enter the String 2  : ");	// Read String 1
	fgets ( str2, BUFFER, stdin );

		
	//validation : 1
	if (*str2 == '\n' ||f_strlen(str2) == 0 || *str2 == '\0' )
	{		
		printf (" Input Should not be empty! \n");
		return 0;
	}
	
	result = strcmp (str1, str2);
	
	if (result == 0)
		printf ("\n Both strings are equal\n");
	
	else if (result == 1)
		printf ("\n String 1 is greater than String 2\n");
	
	else if (result == -1)
		printf("\n String 1 is lesser than string 2\n ");

}

 
