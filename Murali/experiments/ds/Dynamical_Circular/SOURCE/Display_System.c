#include "../HEADER/header.h"

void display_system(struct base_node *base_pointer)
{
	int i = 0;
	int base_count = getListCount(base_pointer);
	
	for(i = 1; i <= base_count ;i++ )
	{
		printf("\n\n\n\nList %d : \n\n", i);
		display_data_begin(base_pointer -> link );
		base_pointer = base_pointer -> next;
		
	}
	
	printf("\n\n");		 
}
