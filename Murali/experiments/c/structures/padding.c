#include<stdio.h>


struct padding
{	
	unsigned short a;
	long long int b;
	unsigned char c;	
};


int main()
{

	static struct padding pad = {0xffff,0xffffffffffffffff,0xff};
	static struct padding pad2 = {0xffff,0xffffffffffffffff,0xff};
	char *p = &pad;
	int i;
	int size = sizeof(pad);
	for(i = 0; i < size; i++)	
	{
		toBbin(p);
		printf("\n");
		p++;
	}
	printf("%d",sizeof(pad));
	printf("%d",sizeof(pad2));
}

void toBbin(char *p)
{
	int i;
	for(i = 1; i <= 8; i++)
	{
		
		printf("%x",((*p >> 7)&1));
		*p = *p<<1;
		if(i==4)
		printf(" ");
	}
}

