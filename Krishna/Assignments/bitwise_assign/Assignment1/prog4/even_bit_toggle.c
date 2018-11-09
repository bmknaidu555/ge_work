
#include <stdio.h>
int even_bit_toggle(unsigned int value)
{
	int size = sizeof(value)*8;
	int count = 0;
	while(count <= (size >> 1)-1)
	{
		printf("%d ",((value >> (size-1)) ^ 1));
		printf("%d ",((value << 1) >> (size-1)) & 1);
		value = value << 2;
				

		count++;
	}

}
