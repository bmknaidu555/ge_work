#include <stdio.h>
#define MAX(M, N, SIZE) ((((M - N) >> SIZE) & 1)? N : M)   

int main()
{
	int num1 ;
	int num2 ;
	int size =  (sizeof (num1) * 8) - 1;
	
	printf("Enter the two number \n");
	scanf("%d %d", &num1, &num2 );
	
	printf("The maximum Number is : %d \n", MAX(num1, num2, size));	
		

	return 0;
}	
