#include "../HEADER/header.h"

void iaprintf(long *list_pointer, unsigned long size)
{
	printf("[ ");
	while( size--)
		printf("%ld ", *(list_pointer++));
	printf("]");
}
