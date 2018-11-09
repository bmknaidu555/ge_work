#include "../HEADER/header.h"

int data_after_value (struct data_node *data_pointer, int value)
{
	struct data_node *temp = NULL;
	int i = 1;
	int pos = -1;

	if (data_pointer == NULL) {
		return -1;
	} else {
		temp = data_pointer;
		do {
			if ((data_pointer -> data) == value) {
				pos = i;
			}
			data_pointer = data_pointer -> next;
			i++;
		} while (data_pointer != temp);
		return pos;
	}
}
