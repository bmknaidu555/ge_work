#include "../HEADER/header.h"

struct base_node *create_begin(int count, struct base_node *base_pointer )
{
		int i;

		if(base_pointer == NULL)
				base_pointer = create();

		struct base_node * temp = NULL;
		for(i = 1; i < count; i++)
		{
				temp = create();
				// point previous of start node to end node
				temp -> prev = base_pointer -> prev ;
				// point next of end node to start node
				(temp -> prev) -> next = temp;
				// point base_pointer prev to temp node
				base_pointer -> prev = temp;
				// 	temp next base_pointer
				temp -> next = base_pointer;
				base_pointer = temp; 
		}
		return base_pointer;
}
