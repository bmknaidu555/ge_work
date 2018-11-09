/* Function bit copy */
// f_bit_copy.c
int bit_copy(snum, dnum, src, dest, n)
{
	dnum = (((snum >> ( ( (src - n) + 1) ) ) & ((1 << n) - 1)) <<  ((dest - n) + 1)) |
								 ( ~ (((1 << n) - 1) << ((dest - n)+1)) & dnum) ;
	return dnum;
}
