int invert_bits(int x, int p, int n)
{
	x =	((((1 << ((p - n) + 1)) - 1) << n) ^ x);
	dec2bin(x);
	return x;
}
