#include<stdio.h>

union sample
{
	int a : 5;
	int b : 10;
	int c : 5;
	int d : 21;
	int e; 
};

int main()
{
	union sample samp;

	samp.e = 1073741824;

	printf("\n The binary value of e is  : \n");
	dec2bin(samp.e);
	printf("\n");
	
	
	printf("a points to first five bits so.. \t ");
	printf("The value of a is %d\n", samp.a);

	printf("b points to first 10 bits so... \t");
	printf("The value of b is %d\n", samp.b);

	printf("c points to first 5 bits so...\t");
	printf("The value of c is %d\n", samp.c);

	printf("d points to first 21 bits so...\t ");
	printf("The value of d is %d\n", samp.d);

}
