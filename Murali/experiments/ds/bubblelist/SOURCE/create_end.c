
#include "../HEADER/header.h"

struct node *create_end(int count, struct node *head)
{	
	int i;

	printf("Enter elements : ");
	if(head == NULL)
		head = create();

	struct node * temp = NULL;
	for(i = 1; i < count; i++)
	{
		temp = create();
		// point previous of start node to end node
		
		temp -> prev = head -> prev;
		(temp -> prev) -> next = temp;
		head -> prev = temp;
		temp -> next = head;	
	}
	return head;	
}
