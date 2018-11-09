#include "../HEADER/header.h"


struct node *create()
{
	int value;
	scanf("%d", &value);
	struct node *temp;
	temp = (struct node *) malloc( sizeof(struct node) );
	temp -> prev = temp;
	temp -> next = temp;
	temp -> data = value;
	return temp;
}
