#include <stdio.h>
#include <stdlib.h>
    
struct node{
    int data;
    struct node *link;
};
void memVal(struct node * temp)
{
	if(temp == NULL){	
		perror ("Memory Allocation Failure");
        exit (EXIT_FAILURE);
	}
}

/* This function creates a new node and returns the reference to calling function */
struct node *createNew (int data)
{
	
    struct node *new = NULL;
    new = (struct node*) malloc (sizeof (struct node));
	memVal (new);
    new -> data = data;
    new -> link = NULL; 
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
        temp -> link = head;
        return temp;
};

struct node *insertMiddle (struct node* head, int data)
{
	if (head == NULL)
		return createNew(data);

	struct node *pointer_1 = head ;
	struct node *pointer_2 = head ;

	while ( (pointer_2 -> link)  != NULL &&
					( (pointer_2 -> link) -> link) != NULL ) {
		pointer_1 = (pointer_1 -> link);	
		pointer_2 = (pointer_2 -> link) -> link;
	}

	//create a new temporary node to insert at middle
	struct node *temp = createNew (data);
	//node created with data and (link part=NULL)

	temp -> link = pointer_1 -> link; 
	pointer_1 -> link = temp;
	return head;

}

struct node * insertEnd (struct node* head, int data)
{
	if( head == NULL )
		return createNew(data);

	struct node *current = head;
	struct node *next = head -> link;	

	while( (NULL != (current -> link)) && (NULL != (next -> link)) ) {
		printf("hello\n");
		current = next -> link;
		next = current -> link;
	}	

	struct node *temp = createNew( data );
	if( (current -> link) != NULL )
		current = next;
	
	current -> link = temp;
	temp -> link = NULL;
	return head;
}

struct node* deleteS(struct node *head)
{
	if(head == NULL) {
         printf("no Nodes to delete");
         return NULL;
    }
    else{
         struct node *temp = NULL;
        temp = head;
         head = head -> link;
         free (temp);
    } 
   	return head;
}


struct node *deleteM (struct node *head)
{
	if (head == NULL){
		printf ("No nodes to delete");
		return head;
	}
	
	if (head -> link == NULL){
		printf ("Deleted Successfully");
		return NULL;
	}
	
	if(((head -> link) -> link) == NULL){
		head -> link = NULL;
		printf("Deleted Successfully");
		return head;
	}
	

	struct node *previous = head; 
	struct node *pointer_1 = head ;
    struct node *pointer_2 = head ;
  
    while ( (pointer_2 -> link)  != NULL &&
                   ( (pointer_2 -> link) -> link) != NULL ) {
		previous = pointer_1;
        pointer_1 = (pointer_1 -> link);
        pointer_2 = (pointer_2 -> link) -> link;
    }

		previous -> link = pointer_1 -> link;
	return head;
	//free ( pointer_1 );
}

struct node *deleteE (struct node *head)
{
	
}

void display (struct node *head)
{
    if(head != NULL){
        printf ("List is empty");
		return;
	}
	printf ("[ ");
    while (head != NULL) {
        printf ("%d ", head -> data);
        head = head -> link;
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

	printf("%d", sizeof (struct node*) );

	printf(" %d", sizeof (struct node) );
    while(1)
    {

        printf ("\n\n1. INSERT at Begin\n2. Insert at Middle\n3. Insert at End\n4. Delete at Begin\n5. Delete at Middle\n6. Delete at End");
        scanf ("%d", &choice);
        
        switch (choice)
        {

            case 1 :
					//inserting at begin
                    printf("Enter the Data : ");
                    scanf("%d", &data);
                    head = insertFirst (head, data);
            		break;
    
			case 2 :
					//inserting at middle
					printf ("Enter the Data :");
					scanf ("%d", &data );
					head = insertMiddle (head, data);
					break;
            case 3 :
					//inserting at end
                	printf ("Enter the Data :");
					scanf ("%d", &data);
					head = insertEnd (head, data);
            		break;
			case 4 : 
					//delete at start
					head = deleteS (head);
					break;
			case 5 :
					//delete at Middle
					 head = deleteM(head);
						break;
			case 6 :
					if (deleteE(head))
						printf ("Node Deleted At End Succesfully");
						break;

        }
        printf ("\nList contains : ");
        display (head);

    }

    return 0;
}
