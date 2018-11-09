
/*
	This Function accepts the address of array of intergers, size of list and reads the input from user.
*/


#include "../HEADER/header.h"

void iascanf(long *list_pointer, unsigned long size)
{
	while( size--)
		scanf("%ld", &(*(list_pointer++)));
}
