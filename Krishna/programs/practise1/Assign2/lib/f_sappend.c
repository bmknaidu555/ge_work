

char* sappend(char* str1, char* str2)
{
	int str1_size = f_strlen(str1);
	int str2_size = f_strlen(str2);
	
	char* temp;
	temp = str2;

	str2 = realloc ( str2, str1_size * (sizeof(char) ));

	str2 = str2 + str2_size;

	*str2 = ' ';
	 str2 ++;
	while( (*str1 != '\n') && (*str1 != '\0') )
	{
		*str2 = *str1;
		 str2 ++;
		 str1 ++;
	}	

	return temp;
}
