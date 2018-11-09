#include "../HEADER/header.h"

int search_max_list (struct data_node *data_pointer, int list_no, int max)
{
	struct data_node *temp = NULL;
	temp = data_pointer;
	do {
		if ((temp -> data) > max) {
			max = temp -> data;
		}
		temp = temp -> next;
	} while (temp != data_pointer);
	return max;
}
