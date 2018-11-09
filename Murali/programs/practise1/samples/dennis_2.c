#include<stdio.h>


long long find_range(int);

int main()
{
	

	printf("Size of integer is %d and its range is %lld ",sizeof(int),
												find_range(sizeof(int)));

printf("%d\n",-(char)((unsigned char)~0 >> 1) - 1);
printf("%d\n",(char)((unsigned char)~0>>1));
}



long long find_range(int range)
{
	range=range*8;
	long long a=1;
	a = a<<range;
	return a;
}
