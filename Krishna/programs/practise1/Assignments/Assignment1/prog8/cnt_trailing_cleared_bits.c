int cnt_trailing_cleared_bits(unsigned int number)
{

	int count = 0;
	int size = (sizeof(number)*8);
	int size_2 = size - 1;
	
	while(size-- != 0)
	{
		
		if((number >> size_2) & 1)
			return count;
			
			count++;
		number = number << 1;		
	}
	return 0;
}
