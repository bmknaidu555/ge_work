#include "../HEADER/header.h"

struct data_node *data_delete_list(struct data_node *data_pointer)
{
	while(data_pointer != NULL)
		data_pointer = data_delete_begin(data_pointer);

	return data_pointer;
}
