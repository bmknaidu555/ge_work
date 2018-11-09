#include<stdio.h>
int leftrotate(unsigned int number)
{
	number = (number << 1)|(number >> (sizeof(number)*8) - 1);
	return number;
}
