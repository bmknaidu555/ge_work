#include "../HEADER/header.h"

struct base_node *create()
{
		struct base_node *temp;
		temp = (struct base_node *) malloc( sizeof(struct base_node) );
		temp -> prev = temp;
		temp -> next = temp;
		temp -> link = NULL;
		return temp;
}

