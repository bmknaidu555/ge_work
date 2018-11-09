#include <stdio.h>
#include <stdlib.h>

//create node structure for data_list
struct node
{
		struct node *prev ;
		int data;
		struct node *next ;		
};

void display (struct node *);

void memVal(struct node * temp)
{
		if(temp == NULL){	
				perror ("Memory Allocation Failure");
				exit (EXIT_FAILURE);
		}
}


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

struct node *create_end(int count, struct node *head)
{	
	int i;

	if(head == NULL)
		head = create();

	struct node * temp = NULL;
	for(i = 1; i < count; i++)
	{
		temp = create();
		// point previous of start node to end node
		
		temp -> prev = head -> prev;
		(temp -> prev) -> next = temp;
		head -> prev = temp;
		temp -> next = head;	
	}
	return head;	
}


struct node *create_begin(int count, struct node *head )
{
	int i;
	if(head == NULL)
		head = create();

			struct node * temp = NULL;
			for(i = 1; i < count; i++)
			{
				temp = create();
				// point previous of start node to end node
				temp -> prev = head -> prev ;
				// point next of end node to start node
				(temp -> prev) -> next = temp;
				// point base_pointer prev to temp node
				head -> prev = temp;
				// 	temp next base_pointer
				temp -> next = head;
				head = temp; 
			}
	return head;
}

void *swap(struct node *node1, struct node *node2)
{
	struct node *temp1 = NULL;
	struct node *temp2 = NULL;

	temp1 = node1 -> next;
	temp2 = node2 -> prev;

	if(node1 == temp2 || node2 == temp1) 
	{
		temp1 = node1;
		temp2 = node2;
	}	
		node1 -> next = node2 -> next;
		(node1 -> next) -> prev = node1;
		node2 -> prev = node1 -> prev;
		(node2 -> prev) -> next = node2;
		node2 -> next = temp1;
		(node2 -> next) -> prev = temp2;
		node1 -> prev = temp2;
		(node1 -> prev) -> next = node1;	
}


struct node *bubble_sort(struct node *head, int n)
{
	int flag =1;
	struct node *i = head;
	struct node *j = head;
	struct node *k = head;


	for(i = head; --n; i = i -> next )
	{
		printf("\n----------main loop\n");
		// To track the head if swapping done at beginning
		if(head -> next != head)
			if( (head -> data) > (head -> next) -> data ){
				head = head -> next;
				swap(k, k -> next);

				if(flag)
				if (head -> next == i)
					i = i -> prev;
	//			printf(" i value is %d", i -> data);
				k = head;	
			}
			
			//	printf("\n");
			//	display(head);
		//		printf("\n");
		
		
		for(j = head; j -> next != head;){
	//			printf("\ninner loop\n");
	//			printf("j -> data = %d", j->data);				
	//			printf("j -> next = %d", (j->next)->data);
				if ( (j -> data) > ((j -> next) -> data) ){


					if(i == j){
						i = j -> next;
					} else if (i == j -> next)
						i = i -> prev;

					swap(j, j -> next);
				} else {
					j = j -> next;
				
			//	printf("\n");		
			//	display(head);
			//	printf("\n");
			}
		}
		flag = 0;
		display(head);
	}

	return head;
}





int main()
{
	struct node *head = NULL;
	int n;
	printf("Enter list size : ");
	scanf("%d", &n);
//	head = create_begin(5, head);
	head = create_end(n, head);
	printf("List created  with %d elements", n);
	head = bubble_sort(head, n);
	//head = selection_sort(head);
	display (head);
	return 0;
}

void  display (struct node *head)
{
        if(head == NULL){
            printf ("List is empty");
    		return;
    	}
		
		struct node *temp = head;

    	printf ("[ ");
		printf("%d ",head -> data);
		head = head -> next;

		int count = 6;

		while (head != temp) {
            printf ("%d ", head -> data);
            head = head -> next;

		}

    	//printf Data formatting for clear understanding
    	printf ("]");	
   // 	printf ("\n%19c\n%19c\n%19c\n\n%21s",'^','|','|',"head");
			
}

