

size_t str_spn(const char* str1, const char* str2)
{
	unsigned int count = 0;
	short flag = 0; 
	unsigned int i = 0;

	while( (*str1 != '\n') && (*str1 != '\0') )
	{
		// if increment str2 ponter it will reaches to end so used i for static incrementing.
		while( (*(str2 + i) != '\n') && (*(str2 + i) != '\0') )
		{
			
			if( *str1 == *(str2 + i) )// comapring individual character in two strings 
			{
				count ++; // Increment and break if matches.
				flag = 1;
				break;
			}
			else 
				i ++ ; // else skip to next character.
		}


		if (flag == 0)
			return count;
		flag = 0;
		i=0;
		str1 ++;
	}
	
	return count;

}
