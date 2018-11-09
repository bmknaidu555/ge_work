#include "../HEADER/header.h"

struct node *insertion_sort( struct node *head )
{
	struct node *i = head;
	struct node *key = head;

	for( i = head; i -> next !=  head; i = i -> next) {
		for(key = i -> next; key != head;) {
			if((key -> data) < (key -> prev) -> data) {
				if(key -> prev == head)
					head = head -> next;
				if(key == i){
					i = i -> prev;
				} else if(key -> prev == i)
					i = i -> next;	
				swap(key, key -> prev);
			}	else
					break;
		}		
	}	
	return head;
}
