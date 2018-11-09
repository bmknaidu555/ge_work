
#include "../HEADER/header.h"

void swap(struct node *node1, struct node *node2)
{
	struct node *temp1 = NULL;
	struct node *temp2 = NULL;

	temp1 = node1 -> next;
	temp2 = node2 -> prev;

	if(node1 == temp2 || node2 == temp1) 
	{
		temp1 = node1;
		temp2 = node2;
	}	
		node1 -> next = node2 -> next;
		(node1 -> next) -> prev = node1;
		node2 -> prev = node1 -> prev;
		(node2 -> prev) -> next = node2;
		node2 -> next = temp1;
		(node2 -> next) -> prev = temp2;
		node1 -> prev = temp2;
		(node1 -> prev) -> next = node1;	
}

