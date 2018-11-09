/*
*	bit_copy.c
*		
*/

#include<stdio.h>	


int prog3()
{
	int snum;
	int dnum;
	int src;
	int dest;
	int n;

	printf("Please enter source number value : \n");
	scanf("%d", &snum);
	
	printf("please enter destination number : \n");
	scanf("%d", &dnum);

	printf("please enter source BIT number : \n");
	scanf("%d", &src);
	
	printf("please enter destination BIT number : \n");
	scanf("%d", &dest);
	
	printf("please enter n value \n");
	printf("NOTE : n value should always less or equal to source and destination\n");
	scanf("%d", &n);

	/*	 validation 1:
	*	 Exit from the execution if user gives n value greater than destiantion or	
															 source
	*/
	if(!((src >= n) && (dest >= n)))
	{
		printf("Note : n value should always be less than source and destination\n");
		return 0;
	}

	printf("The destination number after copying bits is : %d\n", bit_copy(snum,dnum,src,dest,n));
	
return 1;
	
	



		

	 
}
