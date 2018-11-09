#include "../HEADER/header.h"

int search_max_sys (struct base_node *base_pointer, int max)
{
	int count = 1;
	struct data_node *data_pointer = NULL;
	struct base_node *base_node_ref = NULL;
	while (count <= getListCount (base_pointer)) {
		base_node_ref = get_base_node (count, base_pointer);
		data_pointer = base_node_ref -> link;
		max = search_max_list (data_pointer, count, max);
		printf ("%d\n", max);
		count++;
	}
	return max;
}
