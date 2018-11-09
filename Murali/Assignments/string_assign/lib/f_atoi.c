
#include<stdio.h>
#include<stdlib.h>
#define BUFFER 100

int main()
{

	char *a;
	a = (char *)malloc(sizeof(char));
	fgets(a, BUFFER, stdin);
	


printf("The returned integer value is %d ", ato_i(a));

}

int ato_i(char *a)
{
	int value=0;
	
	while(*a != '\0')
	{
		printf("%c", *a);
		if( *a >= 48 && *a <= 57 )
		{
			value = ((value) * 10) + (*a - 48);
		}
		a++;
	}
	return value; 
}
