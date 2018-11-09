#include <stdio.h>
#include <stdlib.h>
    
struct node{
    int data;
    struct node *prev;
	struct node *next;
};


void memVal(struct node * temp)
{
	if(temp == NULL){	
		perror ("Memory Allocation Failure");
        exit (EXIT_FAILURE);
	}
}

struct node *traverseM (struct node *head)
{
	if (head -> next == NULL)
		return head;
	struct node *pointer_1 = head ;
    struct node *pointer_2 = head ; 
    while ( (pointer_2 -> next) -> next  != NULL &&
                       (((pointer_2 -> next) -> next) -> next ) != NULL ) {
		pointer_1 = (pointer_1 -> next);
        pointer_2 = (pointer_2 -> next) -> next;
    }
	return pointer_1;
}

struct node *traverseE (struct node *head)
{
	if( head -> next  == NULL)
		return head;

	struct node *currentNode = head;
	struct node *nextNode = head -> next;	
	while( (NULL != (nextNode -> next)) &&
						 (NULL != (nextNode -> next) -> next) ) {
		currentNode = nextNode -> next;
		nextNode = currentNode -> next;
	}

	return head;
	if(nextNode -> next != NULL)
		currentNode = nextNode;
	return currentNode;
}

struct node *traverseP (struct node *head, int position)
{
	
	while(position-- > 1 && head != NULL){
		head = head -> next;
	}
	return head;
}

/* This function creates a new node and returns the reference to calling function */

struct node *createNew (int data)
{	
    struct node *new = NULL;
    new = (struct node*) malloc (sizeof (struct node));
	memVal (new);
    new -> data = data;
    new -> prev = NULL; 
	new -> next = NULL;
    return new;
}

struct node *insertFirst (struct node * head, int data)
{
    if(head == NULL)
        return createNew(data);

        struct node *temp;
        temp = (struct node*) malloc (sizeof(struct node));    
        memVal (temp);
		temp -> data = data;
        temp -> next = head;
		head -> prev = temp;
		head = temp;
        return head;
}

struct node *insertMiddle (struct node* head, int data)
{
	if (head == NULL)
		return createNew(data);	

	//traverseM (head) will get the middle node from the list
	struct node *middleNode = traverseM (head);
	//create a new temporary node to insert at middle

	struct node *temp = createNew (data);

	// assigning temporary next to new node and temp prev to previous node

	temp -> next = middleNode -> next;

	if (head -> next !=  NULL) 
		(middleNode -> next) -> prev = temp;

	middleNode -> next = temp;
	temp -> prev = middleNode;	
	return head;
}



struct node * insertEnd (struct node* head, int data)
{
	if( head == NULL )
		return createNew(data);
	//traverseE (head) will get the END -1 node from the list
	struct node *endNode = traverseE (head);
	//create a new temporary node to insert at END
	struct node *temp = createNew (data);
	//assigning next end node to newly created node
	printf("%d", endNode -> data);	

	if(endNode -> next == NULL)
		endNode -> next = temp;
	else
		(endNode -> next) -> next = temp;
	// newly created node to previous node
	temp -> prev = endNode;
	return head;

}

struct node *insertPos (struct node *head,int position, int data)
{
		if(position == 0){
			return insertFirst (head, position);
		}

		struct node *posNode = traverseP (head, position);
		struct node *temp = createNew (data);
		// 
		temp -> next = posNode -> next;
		posNode -> next = temp;
		(posNode -> next) -> prev = posNode;
		return head;
}


struct node* deleteS(struct node *head)
{
	if(head == NULL) {
         printf("no Nodes to delete");
         return NULL;
    } else{
			struct node *temp = NULL;
        	temp = head;
         	head = head -> next;
         	free (temp);
    } 
   	return head;
}

struct node *deleteM (struct node *head)
{
	if (head == NULL){
		printf ("No nodes to delete");
		return head;
	}  else if (head -> next == NULL){
		printf ("Deleted Successfully");
		free (head);
		return NULL;
		}
	//will get the middle-1 node from the list
	struct node *middleNode = traverseM (head);
	// point out to the middle node
	struct node *nodeToDelete = middleNode -> next; 
	middleNode -> next  = (middleNode-> next) -> next;
	free(nodeToDelete);
	return head;

}

struct node *deleteE (struct node *head)
{
	if( head == NULL ){
		printf ("No node to delete");
		return head;	
	} else if (head -> next == NULL){
		free (head);
		return NULL;
	}	
	// will get the end node in the list
	struct node *endNode = traverseE (head);
	// point to the node deletebale node in the list
	struct node *deletable = endNode -> next;
	endNode -> next = NULL;
	free(deletable);
	return head;
}

struct node *deleteP (struct node *head, int position)
{
	if(head == NULL){
		printf("No node to delete");
		return head;
	}
	
	if(position == 0)
		return deleteS(head);

	struct node *posNode = traverseP (head, position);
	if(posNode == NULL){
		printf("Invalid Position");
		return head;
	}
	struct node *trash = posNode -> next;
	posNode -> next = (posNode -> next) -> next;
	free(trash);
	return head;
}

void display (struct node *head)
{
    if(head == NULL){
        printf ("List is empty");
		return;
	}
	printf ("[ ");
    while (head != NULL) {
        printf ("%d ", head -> data);
        head = head -> next;
		printf("--> ");
    }
	//printf Data formatting for clear understanding
	printf ("null ");
	printf ("]");	
	printf ("\n%19c\n%19c\n%19c\n\n%21s",'^','|','|',"head");
}

int main ()
{
    struct node *head = NULL;
    int choice;
    int data;
	int position;
    while(1)
    {
        printf ("\n\n1. Insert at Begin\n2. Insert at Middle"
					"\n3. Insert at End\n4. Insert at position"
					"\n5. Delete at Begin\n6. Delete at Middle"
					"\n7. Delete at End\n8. Delete at position");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1 :
					// inserting at begin
                    printf("\nEnter the Data : ");
                    scanf("%d", &data);
                    head = insertFirst (head, data);
            		break;
			case 2 :
					// inserting at middle
					printf ("\nEnter the Data : ");
					scanf ("%d", &data );
					head = insertMiddle (head, data);
					break;
            case 3 :
					// inserting at end
                	printf ("\nEnter the Data : ");
					scanf ("%d", &data);
					head = insertEnd (head, data);
            		break;
			case 4 : 
					// insert at position
					printf ("Enter the position : ");
					scanf ("%d", &position);
				//	validate (poisiton);

						printf ("\nEnter the Data : ");
					scanf ("%d", &data);
					head = insertPos (head, position, data);
					break;
			case 5 : 
					// delete at start
					head = deleteS (head);
					break;
			case 6 :
					// delete at Middle
					head = deleteM(head);
					break;
			case 7 :
					// delete at End
					 head = deleteE (head);
					break;
			case 8 :
					// delete at Position
					printf ("Enter the position");
					scanf ("%d", &position);
				//	validate (position);

					head = deleteP (head, position);
					break;
        }
        printf ("\n\nList contains : ");
        display (head);
    }
    return 0;
}
