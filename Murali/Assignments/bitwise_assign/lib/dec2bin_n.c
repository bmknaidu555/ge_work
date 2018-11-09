
/* Function to convert decimal to binary */

int dec2bin_n(int value, int n)
{

// Right shift it count -1 times and decrement count by 1	
	int n_copy = n;

	while(n != 0)
	{
		printf("%d ", (value >> (n-1) ) & 1); 
		n--;
	}

}
