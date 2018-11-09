#include <stdio.h>
#include <stdlib.h>

unsigned long flread(char **__buffer, int line_no, FILE *_fp)
{
	char char_pointer = 0;
	char data[100];
	int size;
	int counter = 0; 
	int count = 0;
	int i = 0;
	fseek(_fp, 0, SEEK_SET);


	while((size = fread(data, 1, 100, _fp)) > 0)
	{
			
		for(i = 0; (i < size) && count < line_no ; i++)
		{
			if(data[i] == '\n'){
				i++;
				count++;
		}

			if(count == (line_no-1))
			{
				//printf("3");	
				__buffer[line_no - 1][counter] = data[i];
				//printf("%c ",data[i]);
				counter++;
			}
		}

	}
	__buffer[line_no-1][counter] = '\0';
	// function returns the counter as (i.e length(filename)) + 1 
	// +1 is for NULL character '\0' 
	
}
