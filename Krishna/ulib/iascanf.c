#include <stdio.h>
void iascanf(int *list_pointer, unsigned int size)
{
	while( size--)
		scanf("%d",&(*(list_pointer++)));
}
