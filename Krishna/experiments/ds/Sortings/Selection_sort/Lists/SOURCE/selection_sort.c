#include "../HEADER/header.h"

struct node *selection_sort( struct node *head )
{
	
	struct node *ref_pointer = head;

	struct node *i = head;
	struct node *j = head;
	// loop start
	for( i = head; i -> next !=  head; i = i -> next){
		ref_pointer = i;
		
		// loop start
		for(j = i; j -> next != head; j = j -> next)
			if( (ref_pointer -> data) > (j -> next) -> data )
					ref_pointer = j -> next;
		// loop end 

		if(i == head)
			head = ref_pointer;
		if(ref_pointer != i){	
			swap(i, ref_pointer);	
			i = ref_pointer;		
		}	
	}
	// loop end 
	
	return head;
}
