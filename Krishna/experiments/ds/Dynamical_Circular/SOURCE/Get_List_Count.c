#include "../HEADER/header.h"

int getListCount(struct base_node *base_pointer)
{
	if(base_pointer == NULL)
		return 0;
	
	int count = 1;
	struct base_node *temp = base_pointer;
	base_pointer = base_pointer -> next;

	while(base_pointer != temp){
		count++;
		base_pointer = base_pointer -> next;
	}

	return count;
}
