#include "../HEADER/header.h"

struct base_node *create_end(int count, struct base_node *base_pointer)
{	
		int i;

		if(base_pointer == NULL)
				base_pointer = create();

		struct base_node * temp = NULL;
		for(i = 1; i < count; i++)
		{
				temp = create();
				// point previous of start node to end node

				temp -> prev = base_pointer -> prev;
				(temp -> prev) -> next = temp;
				base_pointer -> prev = temp;
				temp -> next = base_pointer;
		}
		return base_pointer;


}
