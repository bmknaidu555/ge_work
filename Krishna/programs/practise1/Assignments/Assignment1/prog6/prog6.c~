#include<stdio.h>

int prog6()
{
	int number;
	int choice;
	int n;
	
	printf("Please enter the number : ");
	scanf("%d", &number);
	
	dec2bin(number);
	printf("\n");

	printf("please choose option : ");
	printf("\n1.one bit left rotate operation");
	printf("\n2.one bit right rotate operation");
	printf("\n3.n bit left rotate operation");
	printf("\n4.n bit right rotate operation");
	scanf("%d", &choice);

	if(choice == 3 || choice == 4)	
	{
		printf("please enter n value ");
		scanf("%d", &n);
	}
	switch(choice)
	{
		case 1 : 
				number = leftrotate(number);
				break;
		
		case 2 :	
				number = rightrotate(number);
				break;
		case 3 :
				number = leftrotate_n(number, n);
				break;
		case 4 :
				number = rightrotate_n(number, n);
				break;
	
		default : 
				printf("Invalid option! Try again.... ");	
	}

	dec2bin(number);

	return 0;
}
