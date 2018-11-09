#include "../HEADER/header.h"

int search_min_sys (struct base_node *base_pointer, int min)
{
	int count = 1;
	struct data_node *data_pointer = NULL;
	struct base_node *base_node_ref = NULL;
	while (count <= getListCount (base_pointer)) {
		base_node_ref = get_base_node (count, base_pointer);
		data_pointer = base_node_ref -> link;
		min = search_min_list (data_pointer, count, min);
		count++;
	}
	return min;
}
