#include<stdio.h>

struct format
{
	unsigned char GFC : 4;
	unsigned char VPI1 : 4;

	unsigned char  VPI2 : 4;
	unsigned char  VCI : 4;

	unsigned char VCI2;
	
	unsigned char VCI3 : 4;
	unsigned char PTI : 3;
	unsigned char CLP : 1;

	unsigned char HEC;
	
}f;


int main()
{
	printf("%d", sizeof(f));

}
