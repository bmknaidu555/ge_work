#include "../HEADER/header.h"

struct data_node *data_delete_after_value (struct data_node *data_pointer , int val)
{
	int pos = search_pos(data_pointer, val);
	if((pos >= (getNodeCount(data_pointer))) || pos < 0){
		printf("Value not found");
		return data_pointer;
}
	if(data_pointer == NULL)
         printf("List is empty\n");
     else if( data_pointer -> next == data_pointer){
			data_pointer = NULL;
			return data_pointer;
	}
	
		data_pointer = data_delete_pos(data_pointer, pos+1);
		return data_pointer;
 	
 	
}
