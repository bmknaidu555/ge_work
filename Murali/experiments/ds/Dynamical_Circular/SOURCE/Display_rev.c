#include "../HEADER/header.h"

void display_rev (struct data_node *data_pointer)
{
	struct data_node *temp = data_pointer;
	
	if(data_pointer == NULL)
	{
		printf("NULL");
		return;
	} 


	printf ("[ ");

		do {
				data_pointer = data_pointer -> prev;
	            printf ("%d ", data_pointer -> data);

		} while (data_pointer != temp);

		//printf Data formatting for clear understanding
		printf ("]");	
}

