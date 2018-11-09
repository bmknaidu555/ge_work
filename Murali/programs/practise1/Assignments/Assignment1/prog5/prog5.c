#include<stdio.h>
#define bit_ts(num, pos) ((1 << pos)|num) 

int prog5()
{
	unsigned int number;
	int position;

	printf("Please enter the number : \n");
	scanf("%d", &number);
	
	dec2bin(number);

	printf("\nplease choose postion from 0 to 31 : \n");
	scanf("%d", &position);

	number = bit_ts(number, position);
	
	dec2bin(number);	
}
