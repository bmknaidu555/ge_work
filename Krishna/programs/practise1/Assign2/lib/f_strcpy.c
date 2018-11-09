//Function str_cpy

/* Function to copy string from one string variable to another variable */

void strcpy(char* dbuf, char* sbuf)
{
	// int size = f_strlen(sbuf);
	 int i;

	// Allocating memory to destination buffer

	for( i = 0;( *(sbuf + i) != '\0' && *(sbuf + i) != '\n') ; i++ )
	{
		*(dbuf + i) = *(sbuf+ i);	
	}
}
