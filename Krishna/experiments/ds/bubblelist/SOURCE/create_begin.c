#include "../HEADER/header.h"

struct node *create_begin(int count, struct node *head )
{
	int i;
	if(head == NULL)
		head = create();


			printf("enter elements : ");
			struct node * temp = NULL;
			for(i = 1; i < count; i++)
			{
				temp = create();
				// point previous of start node to end node
				temp -> prev = head -> prev ;
				// point next of end node to start node
				(temp -> prev) -> next = temp;
				// point base_pointer prev to temp node
				head -> prev = temp;
				// 	temp next base_pointer
				temp -> next = head;
				head = temp; 
			}
	return head;
}
