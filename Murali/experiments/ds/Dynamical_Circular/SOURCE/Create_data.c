#include "../HEADER/header.h"

struct data_node *create_data(int data)
{
	struct data_node *temp = NULL;
	temp = (struct data_node *) malloc(sizeof (struct data_node) );
	temp -> data = data;
	temp -> prev = temp;
	temp -> next = temp;
	return temp;
}
