#include "header.h"
void sread(char *buffer, size_t buffer_size)
{
	int i = 0;
	
	__fpurge(stdin);
	fgets (buffer, buffer_size, stdin);
	while (buffer[i] != '\0')
		i++;
	buffer[i] = '\0';
}

//int setsip_uri()

