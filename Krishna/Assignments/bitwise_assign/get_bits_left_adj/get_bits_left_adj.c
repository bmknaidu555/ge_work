#include<stdio.h>
#include "../lib/f_dec2bin.c"	
#define get_bits(X,P,N)  

int main()
{
	int number_x;
	int number_p;
	int number_n;

	printf("Please enter the number : \n");
	scanf("%d", &number);

	printf("\nThe binary represenation of number you entered is : ");	
	f_dec2bin(number);

	printf("\nplease choose postion from 0 to 31 : \n");
	scanf("%d", &position);

	number = bit_ts(number_x, number_p, number_n);
	number_x = f_get_bits_left_adj(number_x, number_p, number_n);
	
	

		

	f_dec2bin(number);	
}
