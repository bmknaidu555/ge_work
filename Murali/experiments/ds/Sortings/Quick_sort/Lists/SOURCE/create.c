#include "../HEADER/header.h"
	
struct node *create()
{
	struct node *temp = NULL;
	long input;
	scanf("%ld", &input);
	temp = (struct node *) malloc ( sizeof(struct node));
	temp -> data = input;
	temp -> prev = temp;
	temp -> next = temp;
	return temp;
};
