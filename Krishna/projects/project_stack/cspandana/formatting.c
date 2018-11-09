#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char* format_data (char *command, ... )
{
	char *data;
	data = (char*) malloc(30000 * sizeof (char));

	va_list args;	
	va_start (args, command);

	// prints the data into string 		
	vsprintf(data,command, args);	
	//printf("%s", data);
	return data;
	
}

