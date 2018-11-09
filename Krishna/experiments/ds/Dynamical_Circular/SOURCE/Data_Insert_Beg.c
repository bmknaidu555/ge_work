#include "../HEADER/header.h"

struct data_node *data_insert_begin(int data, struct data_node *data_pointer)
{
	if(data_pointer == NULL)
		return create_data( data );

		struct data_node *temp = NULL;
		temp = create_data(data);
		// point previous of start node to end node
		temp -> prev = data_pointer -> prev ;
		// point next of end node to start node
		(temp -> prev) -> next = temp;
		// point base_pointer prev to temp node
		data_pointer -> prev = temp;
		// 	temp next base_pointer
		temp -> next = data_pointer;
		data_pointer = temp; 

		return data_pointer;
}

