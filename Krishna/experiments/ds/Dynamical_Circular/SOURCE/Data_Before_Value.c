#include "../HEADER/header.h"

int data_before_value (struct data_node *data_pointer, int value)
{
	struct data_node *temp = NULL;
	int i = 0;
	if (data_pointer == NULL) {
		return -1;
	} else {
		do {
			if ((data_pointer -> data) == value) {
				return i;
			}
			data_pointer = data_pointer -> next;
			i++;
		} while (data_pointer != temp);
	}
	return -1;
}
