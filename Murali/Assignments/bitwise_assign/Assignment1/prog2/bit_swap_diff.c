int swap(int *src_num, int *dest_num, int src, int dest)
{

int dup_src = *src_num;

/*
	if( ((1 << src) & *src_num) ^ ((1 << dest) & *dest_num) )
	{
		*src_num = ~ (((1 << src) ^ ( ~ (*src_num))));
		*dest_num = ~ (((1 << dest) ^ ( ~ (*dest_num))));
	}
*/

	*src_num = ((*src_num & (~(1 << src))) ^ (((*dest_num >> dest) & 1) << src));
	*dest_num = ((*dest_num & (~(1 << dest))) ^ (((dup_src >> src) & 1) << dest));
		
	return 1;
}
