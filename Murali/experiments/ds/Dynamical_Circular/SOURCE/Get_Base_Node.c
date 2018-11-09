#include "../HEADER/header.h"

struct base_node *get_base_node(int count, struct base_node *base_pointer)
{
	while( count-- != 1)
	{
		base_pointer = base_pointer -> next;
	}
	return base_pointer;	
}

