#include "../HEADER/header.h"

struct data_node *data_delete_pos(struct data_node *data_pointer, int pos)
{
	    
     int i = 0;
     struct data_node *temp = NULL;
     struct data_node *p = NULL;
  
  
     if (0 == pos) {
         return data_delete_begin (data_pointer);
     } 
	else if ((pos >= (getNodeCount(data_pointer))) || (pos < 0)) {
         printf("Invalid position\n");
         return data_pointer;
     }
	 else if (NULL == data_pointer) {
         printf("No data in the list\n");
         return data_pointer;
     }
	 else {
         temp = data_pointer;
         while (++i < pos) {
             temp = temp -> next;
         }
	p = temp -> next;
	temp -> next = (temp -> next) -> next;
	(p -> next) -> prev = temp;
	free(p);
	return data_pointer;
	}
}

