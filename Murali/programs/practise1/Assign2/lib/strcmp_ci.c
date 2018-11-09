
int strcmp_ci(char* str1, char* str2)
{
	int str1_size = f_strlen(str1);
	int str2_size = f_strlen(str2);

	

	while( (*str1 != '\n') && (*str1 != '\0') && (*str2 != '\n') && (*str2 != '\0'))
	{
		if( (*str1 >= 'A' && *str1 <= 'Z'))
		{
			if(!(*str2 >= 'A' && *str2 <= 'Z'))
					*str2 = *str2 - 32 ;
		}

		else if(*str1 >= 'a' && *str1 <= 'z')
		{
			if( !(*str2 >= 'a' && *str2 <= 'z') )
				*str2 = *str2 + 32;		
		}
			
			
			
		if (*str1 > *str2)
			return 1;
		
		else if (*str1 < *str2)
			return -1;
		str1 ++;
		str2 ++;
	}

	if (str1_size == str2_size)
		return 0;
	
	else if (str1_size > str2_size)
		return 1;
		
	else if (str1_size < str2_size)
		return -1;		
}
