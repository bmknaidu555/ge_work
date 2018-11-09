#include <stdio.h>

#if max==1

//To check weather higher datatype is converted to lower or not.

int main()
{

	int data = 2 ;
	float boundary = 3.1;
	float data2 = 6.2 ;
	if( (data2 / data) <= boundary)
	{
		printf("data ");
	}
 
	return 0;
}

#endif

#if max==2
// Formating printf

int main()
{
	printf("The value is %9f %4.7f", 0.5, 0.6); 
}

#endif

#if max==3

// Experimenting the %% character
int main()
{
	printf("%%%%hello");	
}

// Concluded that to print % need to write %%
#endif

#if max==4

// testing %o %x to print octal and hexa decimal

int main()
{
	int value = 45;	
	printf("The value in octal is %o ",value);
	printf("The value in hexa is %x", value);
}
#endif



