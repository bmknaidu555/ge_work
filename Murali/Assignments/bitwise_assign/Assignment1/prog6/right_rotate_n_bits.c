#include<stdio.h>

int rightrotate_n(unsigned int number, int count)
{
	number = (number >> count) | (number << ((sizeof(number)*8) - count));

return number;
}
