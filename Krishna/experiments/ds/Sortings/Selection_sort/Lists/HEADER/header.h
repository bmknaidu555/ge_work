#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
	
struct node *create_list(struct node *, unsigned long);
struct node *create();
void display(struct node*);
void swap(struct node*, struct node*);
struct node * selection_sort(struct node *);



