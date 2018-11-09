
#include "HEADER/header.h"
unsigned long flccount(unsigned long line_no, FILE *_fp)
{
	char data[100];
	unsigned int size;
	unsigned int counter = 0; 
	unsigned int count = 0;
	unsigned int i = 0;
	fseek(_fp, 0, SEEK_SET);


	while((size = fread(data, 1, 100, _fp)) > 0)
	{
			
		for(i = 0; (i < size) && count < line_no ; i++)
		{
			if(count == (line_no-1))
			{
				//	printf("%c", data[i]);	
				counter++;
			}

			if(data[i] == '\n')
				count++;
		}

	}
	
	// function returns the counter as (i.e length(filename)) + 1 
	// +1 is for NULL character '\0' 
	return counter;
}
