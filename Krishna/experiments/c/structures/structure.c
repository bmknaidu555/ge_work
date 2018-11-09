#include <stdio.h>

#if max==1
// checking weather structure without variables take any storage class or not
struct details
{
	int name=3;
	int age=5;
}info2;

int main()
{
	struct details info1 = {};
	printf("%d", info1.name);
}

// consclusion : By default members wont have any storage class
// after declaration of structure variables only storage class is allocated
#endif


#if max==2


struct details
{
	int name;
	int age;
};
static int a=10;

int main()
{
	// struct details info1;
		
}
#endif

#if max==3
//checking weather structure works without a tag or not
struct 
{ 
	int name;
	int age; 
} info3;

int main()
{
	struct data1 = info3;
	printf("%d", info3.name);	
}

//Yes it works with variable declaration statically. but in order to use that struct type in any function we need that tag.

#endif


// checking weather a structure name and varible name will be same or not
#if max==4
struct sam
{
	int name;
	int age;
}sample;
int main()
{
	sample.name = 4;
	printf("%d", sample.name);

}

// It is allowed to declare structure variable same as tag.
#endif


//checking weather two different types of structure can be assigned or not
#if max==5
int main ()
{
/*	struct x
	{
		int x;
		int y;
		
	};
	
	struct y
	{	
		int a;
		int b;	
	};	
*/	//	main();
	auto int main(void);
	main();
	int main ()
	{
		printf("hello world");
/*		struct x x1;
		struct x x2;
		
		x1.x = 1;
		x1.y = 2;
	//	x1.z = 3;
	
		x2 = x1;	
*/	}

}
#endif

//we are only allowed to assign same type of structure to another structure


//Nested structures

#if max==6

struct a
{
	struct b
	{
		int a, b;
	}data1;
};

int main ()
{	
	struct a data1;
	data1.data1.a=5;
	printf("%d",data1.data1.a);
}
#endif

#if max==7

struct a
{
	struct b
	{
		int d;
	};	
};

int main()
{
	struct a inst1;
	struct b d;
	
}

#endif

#if max==8

#pragma pack(1)
struct a
{
 	int a;
	char c;
	int b;
	double d;
}i;

struct b
{
	int a;
	int c;
	int b;
	double d;
}i1;

int main()
{
	printf("%d", sizeof(struct a));
	printf("%d", sizeof(struct b));
}
#endif


#if max==9

struct a 
{
	int a;
unsigned char c;	
int b;
	

};

int Byte(char *p)
{
	int n;
	int i;
	char a = *p;
	for (i=1; i <= 8; i++)
	{
		printf("%d  ",(a&1));
		a = a>>1;			
	}
	printf("\n");
	
}


int main()
{
	struct a a1 ;	
	char *p = &a1;
	int i;
	a1.a = 10;
	a1.b = 10;
	a1.c = 'a';
//	printf("%d",sizeof(a1));
	for(i=0;i<sizeof(struct a);i++)
	{
//		printf("%d\n", *p);
		Byte(p);
	printf("\n");
		

	
		p++;
	}	
}



#endif

#if max==10
struct s1{
	int a;
	int b;
	int c;	
};

int main()
{
	struct s1 a = {0,2,3};
	struct s1 b = {0,1,3};
	//if(a==b);    comparision is not possible on structures
	return 0;
}
#endif



#if max==11


struct point 
{
	int x;
	int y;

};

struct point makepoint(int x, int y)
{
	struct point temp;	
	temp.x = x;
	temp.y = y;
	return temp;

};


struct rect
{
	struct point draw;
	struct point draw2;

};

int main()
{

	struct rect screen;
	screen.draw = makepoint(1,2);

};


#endif



#if max==12

//struct parameters are pass by value 
struct point 
{
	int x;
	int y;

};

struct point makepoint(int x, int y)
{
	struct point temp;	
	temp.x = x;
	temp.y = y;
	return temp;

};


struct rect
{
	struct point draw;
	struct point draw2;

};

struct point addpoints(struct point x,struct point y)
{
	x.x = (x.x + y.x);
	x.y = (x.y + y.y);
}


int main()
{

	struct rect screen;

	screen.draw = makepoint(1, 2);
	screen.draw2 = makepoint(3, 4);

	addpoints(screen.draw, screen.draw2);

	printf("%d",screen.draw.x);
	printf(" %d",screen.draw.y);
};


#endif


#if max==13

//struct parameters are pass by value 
struct point 
{
	int x;
	int y;

};

struct point makepoint(int x, int y)
{
	struct point temp;	
	temp.x = x;
	temp.y = y;
	return temp;

};


struct rect
{
	struct point draw;
	struct point draw2;

};

void addpoints(struct point *pp, struct point *pp1)
{
	(*pp).x = (*pp).x+(*pp1).x;
	(*pp).y = (*pp).y + (*pp1).y;
}


int main()
{

	struct rect screen, *pp;
	pp = &screen;

	screen.draw = makepoint(1, 2);
	screen.draw2 = makepoint(3, 4);

	addpoints(&((*pp).draw),&((*pp).draw2));


	printf("%d",screen.draw.x);
	printf(" %d",screen.draw.y);
};


#endif


#if max==14

struct notations
{
	int len;
	int len2;
};

int main()
{
	struct notations not;
	struct notations *p;
	p = &not;
	
	p -> len  = 2;
	p -> len2 = 4;
	printf("%p",p);
	printf("%p %p  %d",p,++p,p->len);
	char const b= '1';
		int a=1 + sizeof '1';	
	printf("the size is %d",a);	


}

#endif







