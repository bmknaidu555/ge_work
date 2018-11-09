#include "../HEADER/header.h"

int main()
{
	struct node *head = NULL;
	unsigned long size;

	printf("Enter the list size : ");
	scanf("%ld",&size);
	printf("Enter Array elements :");
	head = create_list(head, size);
	printf("\nList created with %ld numbers", size);	
	head =	insertion_sort( head );	
	printf("\nThe sorted List is : \n");
	display( head );
	printf("\n");

	return 0;
}
