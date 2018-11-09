#include <stdio.h>

int fun(void);
int fun2();
int main()
{
	int a = 10;
	int ptr = 20;
	ptr = fun();
}	
int fun(void)
{
	int d = 20;
	int b = 16;
//	d = fun2();
	return 0;
}

int fun2()
{
	return 0;
}
	

