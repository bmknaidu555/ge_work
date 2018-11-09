#include "../HEADER/header.h"

int search_min_list (struct data_node *data_pointer, int list_no, int min)
{
	struct data_node *temp = NULL;
	temp = data_pointer;
	do {
		if ((temp -> data) < min) {
			min = temp -> data;
		}
		temp = temp -> next;
	} while (temp != data_pointer);
	return min;
}
