#include "../HEADER/header.h"

int main()
{
	struct node *head = NULL;
	char choice;
	int list_size;
	int list_count = 0;

	while(1){
	printf(
			"1. CREATE LIST WITH INSERT BEGIN\n"
			"2. INSERT LIST WITH INSERT LAST\n"
			"3. SORTING\n"
			"4. SEARCHING\n"
			"5. DISPLAY\n\n"
		  );
	__fpurge(stdin);
	scanf("%c", &choice);
	switch(choice - 48)
	{
		case 1 :
				/* Create List by inserting at begin*/
				
				if(head != NULL)
					printf("List is created....");
				printf("Enter the list size :");
				scanf("%d", &list_size);
				list_count = list_size; 	
				head = create_end(list_count, head);
				printf("\nList created with %d elements\n", list_size);
			
				break;
		case 2 :
				/* Create list by inserting at end */	
					
				if(head != NULL){
					printf("List is already created....");
					break;
				}
				printf("Enter the list size :");
				scanf("%d", &list_size);
				list_count = list_size; 	
				head = create_end(list_count, head);
				printf("\nList created with %d elements\n", list_size);
	
				break;
		case 3 :				
				/* Sort */
				
				printf(	
						"1. BUBBLE SORT\n"
						"2. SELECTION SORT\n"
						"3  INSERTION SORT\n"
						"4. QUICK SORT\n"
						"5. MERGE SORT\n"	
					  );
				__fpurge(stdin);
				scanf("%c", &choice);

				switch(choice - 48)
				{
					case 1 :		
							head = bubble_sort(head, list_count);
							break;	
					case 2 :
							
							head = selection_sort(head, list_count);
							break;
					
					case 3 :		
							//head = insertion_sort(head, list_count);
							break;
					case 4 :	
							//head = quick_sort(head, list_count);
							break;
					case 5 :	
							//head = merge_sort(head, list_count);
							break;
				}	
				break;
		case 4 :
				
				/* Search */
				break;	
		case 5 : 
				/* Display */
				display(head);
				printf("\n");
				break;
		case 6 : 
				/* display */
				break;
	}
}
	return 0;
}
