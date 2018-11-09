#include<stdio.h>	


int prog7()
{
	unsigned int number;
	
	printf("Enter the number : ");
	scanf("%d", &number);
	printf("The count of set bits are %d\n", count_bit_set(number));
	printf("The count of cleared bits are %d\n",count_bit_clear(number));
	
	return 0;
}
