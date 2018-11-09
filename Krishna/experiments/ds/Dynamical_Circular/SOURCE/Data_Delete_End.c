#include "../HEADER/header.h"

struct data_node *data_delete_end (struct data_node *data_pointer)
{
	struct data_node *temp = NULL;
    if(data_pointer == NULL){
		printf("List is empty");
	}

	else if(data_pointer -> prev == data_pointer ){
		data_pointer = NULL;
		return data_pointer;
	}
	
	else {
		temp = data_pointer -> prev;
		(temp -> prev) -> next = data_pointer;
		data_pointer -> prev = temp -> prev;
		}
	return data_pointer;
}

