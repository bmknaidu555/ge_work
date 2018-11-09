#include <stdio.h>
#define MAX(N1, N2) ((N1 - N2)-(-N2))  

int main()
{
	int num1 ;
	int num2 ;

	printf("Enter the two number \n");
	scanf("%d %d", &num1, &num2 );
	
	printf("%d", MAX(num1, num2));	
	printf("%d", ((num1-num2)-(-num2)));	

	return 0;
}	
