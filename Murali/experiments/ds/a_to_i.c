int a_to_i (char *input)
{	
	printf("Entred into ato i");
	short sign = 1;
	int i = 0;
	int total = 0;
	int result = 0;	
	
	if(*(input + i) == '-')
		sign = -1;

	while((*(input + i ) != '\0') && *(input + i) != '\n'){
		if(*(input + i) >= '0' && *(input + i) <= '9')
			total = total + ((*(input + i) - 48) * 10); 
	}
	if(sign == -1)
		return -(total);
	return total;
}
