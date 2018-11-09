#include "../HEADER/header.h"

struct data_node *data_delete_begin (struct data_node * data_pointer)
{
	 struct data_node *temp = NULL;
	 struct data_node *temp1 = NULL;
     temp = data_pointer -> next;
	temp1 = data_pointer;
   	
	 if(data_pointer == NULL)
         printf("List is empty");
     else if((data_pointer -> next) == data_pointer) {
		data_pointer = NULL;
		return data_pointer;
	 } else {
 		temp -> prev = data_pointer -> prev;
		(data_pointer -> prev) -> next = temp;
		data_pointer = temp;
		free(temp1);
    }
     return data_pointer;
}
