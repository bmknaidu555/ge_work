char* f_chr_add_instr (char *buf, char ch)
{
	int position = 0;
	while(*buf != '\0' && *buf != '\n')
	{
		if(*buf == ch)
		{
			printf("The character found at position %d ", position);
			return buf;
		}

		position++;
		buf++;
	}
return buf;

}
