/**
*
*
*
*
**/

#include<stdio.h>



int prog2(void)
{
	
	int snum;
	int dnum;
	int src;
	int dest;

	printf("please enter source number\n");
	scanf("%d", &snum);

	printf("The binary of source number before swapping  is :  \n");
	dec2bin(snum);

	printf("\nplease select source bit number to swap\n");
	scanf("%d", &src);

	printf("please enter destination number\n");	
	scanf("%d", &dnum);

	printf("The binary of destination number before swapping is : \n");
	dec2bin(dnum);	

	printf("\nplease select the destination bit number to swap\n");
	scanf("%d", &dest);

	if(swap(&snum, &dnum, src, dest))
	{	
		printf("\n\nThe source number after swapping with dest bit is : %d \n", snum);
		dec2bin(snum);	
		
		printf("\n\nThe destination number after swapping with source bit is : %d \n\n", dnum);
		dec2bin(dnum);
		printf("\n");
	}
	
	else
		printf("\nThere is an error while swapping bits");

	return 0;

} 
