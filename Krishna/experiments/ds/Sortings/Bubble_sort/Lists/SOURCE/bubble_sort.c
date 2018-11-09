#include "../HEADER/header.h"

struct node *bubble_sort( struct node *head )
{
	

	struct node *i = head;
	struct node *j = head;
	struct node *temp = head;	
	for( i = head; i -> next != head; i = i -> next, temp = temp -> prev ){

		for(j = head; j -> next != temp;){

			if( (j -> data) > (j -> next) -> data ){
				if(i == j)
					i = i -> next;
				else if(i == j -> next)
					i = i -> prev;
				
				/* maintainig the termination condition () for j loop */
				if( j == temp)	
					temp = temp -> next; 
				else if(j -> next == temp)
					temp = temp -> prev;
				/* checking weather head is changing or not */
				if(head == j)
					head = head -> next;	

				swap(j, j-> next);
			} else {
				j = j -> next; 
			}
		}

	}

return head;
}
