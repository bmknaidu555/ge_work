	#include <stdio.h>
    #include <stdlib.h>
    #define BUFFER 100
	 
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

	void charmemVal(char *temp)
	{		
    	if(temp == NULL){	
    		perror ("Memory Allocation Failure");
            exit (EXIT_FAILURE);
		}
	}
     
    struct node *traverseM (struct node *head)
    {
    	if (head -> link == NULL)
    		return head;
    	struct node *pointer_1 = head ;
        struct node *pointer_2 = head ; 
        while ( (pointer_2 -> link) -> link  != NULL &&
                           (((pointer_2 -> link) -> link) -> link ) != NULL ){
    		pointer_1 = (pointer_1 -> link);
            pointer_2 = (pointer_2 -> link) -> link;
        }
    	return pointer_1;
    }

    struct node *traverseE (struct node *head)
    {
    	if( head -> link  == NULL)
    		return head;

    	struct node *current = head;
    	struct node *next = head -> link;	

    	while( (NULL != (next -> link)) &&
    						 (NULL != (next -> link) -> link) ) {
    		current = next -> link;
    		next = current -> link;
    	}

    	if(next -> link != NULL)
    		current = next;

    	return current;
    }
     
    struct node *traverseP (struct node *head, int position)
    {
     
    	while(position-- > 1 && head != NULL){
    		head = head -> link;
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
    }
     
    struct node *insertMiddle (struct node* head, int data)
    {
    	if (head == NULL)
    		return createNew(data);	
    	//traverseM (head) will get the middle node from the list
    	struct node *middleNode = traverseM (head);
    	//create a new temporary node to insert at middle
    	struct node *temp = createNew (data);
    	temp -> link = middleNode -> link;
    	middleNode -> link = temp; 
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
     
    	if(head -> link == NULL)
    			head -> link = temp;	
    	else
    		(endNode -> link) -> link  = temp;
    	return head;
    }
     
    struct node *insertPos (struct node *head,int position, int data)
    {
    		if(position == 0){
    			return insertFirst (head, data);
    		}

			if (head == NULL || position < 0){
				printf("\nInvalid Position");
				return head;
			}
    		struct node *posNode = traverseP (head, position);
			
			// if head reaches NULL before reaching to position return head
			if(posNode == NULL){
				printf("\nInvalid Position");
				return head;
			}

    		struct node *temp = createNew (data);
    		temp -> link = posNode -> link;
    		posNode -> link = temp;
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
    	}  else if (head -> link == NULL){
    		printf ("\nDeleted Successfully");
    		free (head);
    		return NULL;
    		}
    	//will get the middle-1 node from the list
    	struct node *middleNode = traverseM (head);
    	// point out to the middle node
    	struct node *nodeToDelete = middleNode -> link; 
    	middleNode -> link  = (middleNode-> link) -> link;
    	free(nodeToDelete);
    	return head;
     
    }
     
    struct node *deleteE (struct node *head)
    {
    	if( head == NULL ){
    		printf ("No node to delete");
    		return head;	
    	} else if (head -> link == NULL){
    		free (head);
    		return NULL;
    	}	
    	// will get the end node in the list
    	struct node *endNode = traverseE (head);
    	// point to the node deletebale node in the list
    	struct node *deletable = endNode -> link;
    	endNode -> link = NULL;
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
    	} else if (posNode -> link == NULL){
			printf("Invalid Position");
			return head;
		}
    	struct node *trash = posNode -> link;
    	posNode -> link = (posNode -> link) -> link;
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
		int *value;
		int choice;
        int data;
    	int position;
        while(1)
		{
				printf ("\n\nInsert--  1. Begin\t2. Middle"
    					"\t3. End\t4. At position"
    					"\n\nDelete--  5. Begin\t6. Middle"
    					"\t7. End\t8. At position"
						"\n\nEnter the choice : ");
            value = is_integer();
			__fpurge(stdin);	
			if(value == NULL){
				printf("Invalid Input");
				continue;	
			}		
			int choice = *value;
			printf("%d", choice);
			switch (choice)
            {
                case 1 :
    					// inserting at begin
                        printf("\nEnter the Data : ");
						value = is_integer();
						if(value == NULL){
							printf("INVALID DATA");
							continue;
						}
						choice = *value;
						printf("%d", choice);
					    head = insertFirst (head, data);
                		break;
    			case 2 :
    					// inserting at middle
    					printf ("\nEnter the Data : ");
						//data = scani();
    					head = insertMiddle (head, data);
    					break;
                case 3 :
    					// inserting at end
                    	printf ("\nEnter the Data : ");
						//data = scani();
						head = insertEnd (head, data);
                		break;
    			case 4 : 
    					// insert at position
    					printf ("Enter the position : ");
    				//	position = scani(); 
    					printf ("\nEnter the Data : ");
    					//data = scani();
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
    					//scani();
    					//	validate (position);
    					head = deleteP (head, position);
    					break;
				default : 
						printf("Invalid Choice");
            }
		
            printf ("\n\nList contains : ");
            display (head);
        }
        return 0;
    }



