#include <stdio.h>
#include <stdlib.h> 
#include "lib/f_strcpy.c"
#include "lib/f_strlen.c"
#define BUFFER 50

int main()
{
	// Source buffer
	char* sbuf = malloc( BUFFER );
	
	// Destination buffer
	char* dbuf ;
	
	// Reading input from user
	fgets(sbuf, BUFFER, stdin);

	dbuf = malloc(f_strlen(sbuf));	

	//copying the string from source to destination
	strcpy(dbuf, sbuf);
	
	printf("%s", dbuf);
}

 
