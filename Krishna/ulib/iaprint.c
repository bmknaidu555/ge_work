#include <stdio.h>

/* This function is used to print the elements in array */
/* integer array print */

void iaprintf(int *list_pointer, unsigned int size)
{
	printf("[ ");
	while( size-- )
		printf("%d ",*(list_pointer++));
	printf("]");
}
