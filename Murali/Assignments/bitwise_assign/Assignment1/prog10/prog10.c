#include<stdio.h>

int prog10()
{
	int number_x;
	int number_y;
	int number_p;
	int number_n;
	
	printf("Please enter the x value : ");
	scanf("%d", &number_x);
	
	printf("Please enter the y value : ");
	scanf("%d", &number_y);

	printf("The binary representation of x value is : ");
	dec2bin(number_x);

	printf("\n");
	
	printf("The binary representation of y value is : ");
	dec2bin(number_y);

	printf("\n");

	printf("Please enter how many values you want to replace in x from y:");
	scanf("%d", &number_n);

	printf("please select the position in x : ");
	scanf("%d", &number_p);
	
	if((number_n-1) <= number_p)
	{
		number_x = setbits(number_x, number_y, number_n, number_p);
	}

	printf("After replacing the bits in value of x with y is : ");
	dec2bin(number_x);

	return 0;
}
