#include "../HEADER/header.h"

int search_pos(struct data_node *data_pointer, int value)
{
	struct data_node *temp = NULL;
	int node = 0;
	temp = data_pointer;
	do {
              if ((temp -> data) == value) {
              	return node;
              }
              node = node + 1;
              temp = temp -> next;
          } while (temp != data_pointer);
	return 0;
}
