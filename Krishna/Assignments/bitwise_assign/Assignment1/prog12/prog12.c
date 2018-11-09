#include<stdio.h>


#define get_bits(X,P,N) ( (X >> P) & ((1 << N) - 1) ) 

int prog12()
{
	int number_x;
	int number_p;
	int number_n;

	printf("Please enter the number : \n");
	scanf("%d", &number_x);

	printf("\nThe binary represenation of number you entered is : ");	
	dec2bin(number_x);

	printf("\nplease choose postion from 0 to 31 : \n");
	scanf("%d", &number_p);

	printf ("\nPlease enter n Value : \n");
	scanf("%d",&number_n);
	
	number_x = get_bits(number_x, number_p, number_n);
	
	printf ("\nThe Extracted Bits are : ");
	
	dec2bin_n(number_x, number_n);
	
	printf("\n");
//	dec2bin(number_x);	
}
