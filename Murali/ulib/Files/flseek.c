#include <stdio.h>

FILE *flseek(const unsigned int line_no, FILE *fp)
{
	char buffer [100];
	short seek_status;
	size_t i;
	int size;
	int count = 0;
	size_t position = 0;

	while ((size = fread(buffer, 1, 100, fp)) > 0)
	{
		fwrite(buffer, size, 1, stdout);
		for(i = 0; i < size; i++){
			if(buffer[i] == '\n')
				count++;
			if(count == line_no)
				return fp;
		}
	}
	printf("%ld\n", ftell(fp));

	printf("%d %d", count, position);
		
}
