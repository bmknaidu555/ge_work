


int f_strlen(char* str)
{
	
	int count=0;

	while(*str != '\0' && *str != '\n')
	{
		count ++;
		str++;
	}

	return count;

}

