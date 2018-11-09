#include "../HEADER/header.h"

void display_data_begin(struct data_node *data_pointer)
{
	struct data_node *temp = data_pointer;
	
	if(data_pointer == NULL)
	{
		printf("NULL");
		return;
	} 


	printf ("[ ");
	printf("%d ", data_pointer -> data);	
	data_pointer = data_pointer -> next;
	

		while (data_pointer != temp) {
	            printf ("%d ", data_pointer -> data);
				data_pointer = data_pointer -> next;

		}

		//printf Data formatting for clear understanding
		printf ("]");	
}

