#include "../HEADER/header.h"

struct node *create_list(struct node *head, unsigned long count)
{
	if(head == NULL){
		head = create();
	}
	count--;
	struct node *temp = NULL;

	while( count--  ){
		temp = create();
		temp -> prev = head -> prev;
		(temp -> prev) -> next = temp;
		temp -> next = head;
		head -> prev = temp;	
	}	
	return head;		
}
