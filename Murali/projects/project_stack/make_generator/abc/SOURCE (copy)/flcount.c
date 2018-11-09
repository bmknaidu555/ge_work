#include<stdio.h>
#include<stdlib.h>
unsigned long flcount(FILE *_fp)
{
	char data[100];
	int size;
	int count = 0;
	int i = 0;

	fseek(_fp, 0, SEEK_SET);

	while((size = fread(data, sizeof(char), 100, _fp)) > 0)
	{	
		for(i = 0; i < size; i++)
		{
			if(data[i] == '\n')
				count++;
		}
	}	
	return count;
}
