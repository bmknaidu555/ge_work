int str_len (char *input)
{
	unsigned int  i = 0;
	while (*(input + i) != '\0')
		i ++;
	return i;
}
