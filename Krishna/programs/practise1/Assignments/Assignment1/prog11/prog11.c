#include<stdio.h>	


int prog11()
{
	int number_x;
	int number_p;
	int number_n;
		
	printf("Please enter x value \n");
	scanf("%d", &number_x);
	
	printf("The binary representation of x is : ");
	dec2bin(number_x);

	printf("\n");	

	printf("please enter how many values you want to invert in x : \n");
	scanf("%d", &number_n);	

	printf("Please select the position in x :\n NOTE : Indexing starts from 0 :\n");
	scanf("%d", &number_p);	
	
	number_x = invert_bits(number_x, number_p, number_n);
	
	printf("Binary representation after inverting  x is : ");
	dec2bin(number_x);
	
	return 0;

}
