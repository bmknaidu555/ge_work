#include "header.h"

/* Reading the input string and replacing the \n */ 
char* fsread(char *buffer, size_t buffer_size, FILE *ptr)
{
	unsigned int i = 0;

	__fpurge(stdin);
	//if(fgets (buffer, buffer_size, ptr) == NULL)
	//	return NULL;
	
	while (buffer[i] != '\0') {
		if(buffer[i] == ' ') {	
			buffer[i] = '\0';
		}
	}
}

void iread()
{
	__fpurge(stdin);
	
}


