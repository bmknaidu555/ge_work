#include<stdio.h>
int leftrotate_n(unsigned int number, int count)
{
	number	=	((number << count)|(number >> (((sizeof(number)*8) - count))));
	dec2bin(number);
	printf("\n");
	return number;
}
