#include "../HEADER/header.h"

struct data_node *data_insert_pos(struct data_node *data_pointer , int pos, int data)
{
	int i = 0;
	struct data_node *new = NULL;
	struct data_node *temp = NULL;
	struct data_node *temp1 = NULL;
	
	if (pos == 0){
		return data_insert_begin(data, data_pointer);
	}
	else if((pos > (getNodeCount(data_pointer))) || (pos < 0)){
		printf("Invalid position\n");
		return data_pointer;
	}
	else if (pos == getNodeCount(data_pointer))
		return data_insert_end(data, data_pointer);
	else {
	temp = data_pointer;
	temp1 = temp;
	new = create_data(data);
		while(i < pos){
			temp1 = temp;
			temp = temp -> next;
			i++;
		}
	new -> next = temp;
	temp -> prev = new;
	temp1 -> next = new;
	new -> prev = temp1;
	}
return data_pointer;
}
