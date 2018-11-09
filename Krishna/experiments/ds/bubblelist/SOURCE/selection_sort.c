#include "../HEADER/header.h"

struct node *selection_sort(struct node *head, int n)
{
	struct node *i = head;
	struct node *j = head;
	struct node *j_ref = NULL;
	char flag = 49;

	while(--n)
	{		
		printf("------------ > main");	
		for(j = i; j -> next != head; ){
				display(head);

				printf("\n");

				printf("\ninner");
					
					printf("%d  > %d", i -> data, (j -> next) -> data);
				if ( (i -> data) > ((j -> next)-> data ) ){
					j_ref = j -> next;
					swap(i, j -> next);
					i = j_ref;

					printf("value of flag is %c", flag);
							
					if(flag){
					printf("*********");
					head = i;
					}

				}
				
				else
						j = j-> next;
		}
		flag = 0;
		printf("%d", head->data);
		return head;
		i = i -> next;
		printf("\n");
//i = i -> next;
		printf("============>");
		display(head);
	
		
	}

	return head;
}
