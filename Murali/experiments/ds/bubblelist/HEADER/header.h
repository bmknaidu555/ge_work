#include <stdio.h>
#include <stdlib.h>

struct node
{
		struct node *prev ;
		int data;
		struct node *next ;		
};

void display(struct node *);
void memVal(struct node *);
struct node *create();
struct node *create_end(int , struct node *);
struct node *create_begin(int, struct node *);
void swap(struct node *, struct node *);
struct node *bubble_sort(struct node *, int);
