#include <stdio.h>
#include <stdlib.h> 
#include "lib/f_strncpy.c"
#include "lib/f_strlen.c"
#define BUFFER 50

int main()
{
	int n;
	int input_length;

	// Source buffer
	char* sbuf = malloc( BUFFER );
	
	// Destination buffer
	char* dbuf ;
	
	printf ("Please enter The input String   :  \n");

	// Reading input from user
	fgets ( sbuf, BUFFER, stdin );

	input_length = f_strlen ( sbuf );

	printf("Please enter n value  :  \n");
	scanf("%d", &n);

	//Validation : 0 
	if(n > input_length || n == 0)
	{
		printf("N value should always < than or = to input string and not = 0\n");
		return 0;
	}

	dbuf = malloc ( f_strlen(sbuf) );	

	//copying the string from source to destination
	f_strncpy (dbuf, sbuf, n);
	
	printf ("%s\n", dbuf);
}

 
