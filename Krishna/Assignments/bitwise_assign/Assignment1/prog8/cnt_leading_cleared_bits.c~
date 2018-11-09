int cnt_leading_cleared_bits(int number)
{

	int count = 0;
	int size = (sizeof(number)*8);

	while(size-- != 0)
	{
		if(number & 1)
			return count;

		count++;
		number = number >> 1;		
	}
	return 0;
}
