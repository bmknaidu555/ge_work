#include <stdio.h>
#include <stdlib.h> 
#include "lib/f_strncpy.c"
#include "lib/f_strlen.c"
#include "lib/f_chr_add_instr.c"
#define BUFFER 50

int main()
{
	int n;
	int input_length;

	// Source buffer
	char* buf = malloc( BUFFER );
	
	printf ("Please enter The input String   :  \n");

	// Reading input from user
	fgets ( buf, BUFFER, stdin );

	printf("Please enter the character  :  ");
	char ch = fgetc(stdin);

	buf = f_chr_add_instr (buf, ch);	

	if( *buf == '\0' || *buf == '\n' );
	{
		printf("Character not found...   please Try Again!\n");
		return 0;
	}
	printf("The address is  : \n ");
	

	printf ("%p\n", buf);
}

 
