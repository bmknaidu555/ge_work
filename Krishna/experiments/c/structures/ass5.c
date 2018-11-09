#include<stdio.h>
struct endian 
{
	int a;
};


int main()
{
	struct endian end;

	char *input;
	char *pointer;

	input = malloc(8*sizeof(char));

	printf("Enter the four bytes value in hexadecimal : ");
	printf("example : 12345678 or 34567890");

	fgets(input,9,stdin);
	
	int data = atoi(input);
	pointer = &data;

	if((*pointer) == atoi((input+5)));
		printf("%s",*(input+5));
	
	
//	printf()
	
			

//	char *pointer = &(end.a);	
//	pointer++;
	
//	printf("%x", *pointer);	
	
}
