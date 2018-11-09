#include<stdio.h>

struct rect* a(void);
struct rect* a2(void);

struct rect
{
	int ret1;
	int ret2;
};

int main()
{

	struct rect *abc,*def;
	abc = a();
	def = a2();
	
	printf("%d",abc->ret1);

}

struct rect* a()
{
	struct rect b={1,3};
	printf("%p %p %p\n",(&b),(&b)+1,&(b.ret2));
	return &b;
}


struct rect* a2()
{
	struct rect b={3,7};
	return &b;
}
