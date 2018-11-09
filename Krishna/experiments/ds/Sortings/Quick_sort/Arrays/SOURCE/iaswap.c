#include "../HEADER/header.h"

void swap(long *a, long *b)
{
	long temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
