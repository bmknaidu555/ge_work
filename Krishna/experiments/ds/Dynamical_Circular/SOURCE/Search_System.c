#include "../HEADER/header.h"

void search_sys (struct base_node *base_pointer, int *value)
{
    int count = 1;
	int search = 0;
    struct data_node *data_pointer = NULL;
    struct base_node *base_node_ref = NULL;
	while (count <= getListCount (base_pointer)) {
        base_node_ref = get_base_node (count, base_pointer);
        data_pointer = base_node_ref -> link;
		search = search_val (data_pointer, &count, value);
		if (search) {
	        printf ("Number of matching in list %d is %d\n\n", count, search);
      	} else {
			printf ("value %d is not fount in list %d\n", *value, count);
		}
		count++;
    }
}
