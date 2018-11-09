#include "../HEADER/header.h"

void  display (struct base_node *base_pointer)
{
		if(base_pointer == NULL){
				printf ("List is empty");
				return;
		}

		struct base_node *temp = base_pointer;

		printf ("[ ");
		printf("%p -->",base_pointer -> link);
		base_pointer = base_pointer -> next;

		while (base_pointer != temp) {
	            printf ("%p", base_pointer -> link);
				base_pointer = base_pointer -> next;
				printf("--> ");

		}

		//printf Data formatting for clear understanding
		printf ("null ");
		printf ("]");	

}

