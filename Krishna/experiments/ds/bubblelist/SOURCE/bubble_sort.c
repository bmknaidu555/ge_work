#include "../HEADER/header.h"

struct node *bubble_sort(struct node *head, int n)
{
	struct node *i = head;
	struct node *j = head;
	struct node *k = head;


	for(i = head; --n; i = i -> next )
	{
		// To track the head if swapping done at beginning
		if(head -> next != head)
			if( (head -> data) > (head -> next) -> data ){
				head = head -> next;
				swap(k, k -> next);
				k = head;	
			}
			
		
		for(j = head; j -> next != head;){
				if ( (j -> data) > ((j -> next) -> data) )
					swap(j, j -> next);
				else 
					j = j -> next;
			
		}
	}

	return head;
}
