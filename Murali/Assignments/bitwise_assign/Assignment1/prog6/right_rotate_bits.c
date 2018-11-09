#include<stdio.h>

int rightrotate(unsigned int number)
{
	number = (number >> 1)|(number << (sizeof(number)*8) - 1);
	return number;
}
