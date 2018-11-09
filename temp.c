#include <stdio.h>

int main()
{
	char abc[100];
	FILE *fp = NULL;
	fp = fopen("employee.txt","r");
	int i;
	for(i = 0; i<3; i++)
	{
		fgets(abc, 100, fp);
		printf("%s", abc);
	}
}

