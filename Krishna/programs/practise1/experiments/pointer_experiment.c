#include<stdio.h>


// checking weather a normal variable can hold the address of another variable 

#if max==1
int main()
{
	int x = 1;
	int y = 2;
	y = &x;
 
	printf("%p", &x);
	printf("\n%p", y);
	
	return 0;
}
#endif

//changing the value of constant variable using pointer

#if max==2
int main()
{
const int b = 10;
int *a;
a = &b;
*a = 20;
//int p = *a;
printf(" %d", b);

}
#endif

// checking weather we can change the value of constant pointer or not

#if max==3

int main()
{
	const int *p;
	int a = 10;
	int b = 20;
	p = &a;
	p = &b;

}
#endif

#if max==4

int main()
{
	register int a = 10;
	int *p;
	p = &a
}
#endif

#if max== 5
int *p1, data(char *);

int main()
{
	char *p1;
	char a = 10;
	p1 = &a;
	printf("%p\n", p1);
	p1++;
	printf("%p", p1);
	//p = &a;
	//*p1 = (int *)&a;
//	printf("%d", a);	
}
#endif


#if max==6
int main()
{
	char a;

  a=  getchar();
	printf("%c",a);
}

#endif

// checking how many bytes that a character pointer points to integer variable(Either 1 or 4 Bytes);


#if max==7 
int main()
{
	int a = 150;
	char *b;
	b = &a;
	printf("%d",*b);  	
}

#endif

// to check the precedence of arithmentic operator

#if max==8
int main()
{
	int a=10;
	int b=20;
	int *p1=&a;
	int *p2=&b;

	int d = ++(*p1) - ++(*p2)+ --(*p1);
printf("%d",d);
}
#endif

#if max==9

int main()
{
	int a=10;				
	int *p;
	p = & a;
	printf("%d",* p);
}
#endif

#if max==10

int main()
{
	int a[4]={1,2,3,4};
	
//printf("%d",*a);
	
	printf("%d", *(a+1));
}
#endif

#if max==11

int main()
{ 
	
}
#endif
