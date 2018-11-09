#include<stdio.h>

int main()
{
	int a = 3;
	char *b = &a;
	a = a;
//	b = ptr + sizeof(int*) + 1;	
	*b = *b;
	printf("%d", *b);
}
