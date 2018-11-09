
#include "../HEADER/header.h"

void display (struct node *head)
{
        if(head == NULL){
            printf ("List is empty");
    		return;
    	}
		
		struct node *temp = head;

    	printf ("[ ");
		printf("%d ",head -> data);
		head = head -> next;

		while (head != temp) {
            printf ("%d ", head -> data);
            head = head -> next;

		}

    	//printf Data formatting for clear understanding
    	printf ("]");	
   // 	printf ("\n%19c\n%19c\n%19c\n\n%21s",'^','|','|',"head");
			
}
