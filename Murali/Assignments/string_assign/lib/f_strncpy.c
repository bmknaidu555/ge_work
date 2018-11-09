
void f_strncpy(char* dbuf, char* sbuf, int n)
{
	int i;
	
	for(i=0; i < n ; i++)
	{
		*(dbuf + i) = *(sbuf + i);
	}
}
