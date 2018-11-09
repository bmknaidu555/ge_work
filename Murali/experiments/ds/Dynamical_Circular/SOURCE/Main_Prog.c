#include "../HEADER/header.h"

int main (void)
{
		// handler to the base list 0
	struct base_node *base_pointer = NULL;

		// handler to the data list in level 1
	struct data_node *data_pointer = NULL;
	struct base_node *base_node_ref = NULL;

	int choice_1;
	int no_nodes;					
	int choice;
	int data;
	int list_no;
	int position;
	int value;
	int max;
	int min;
	int attempt1 = 3;
	int attempt2;
	while(attempt1) {
		printf (	
				"================================================\n"
				"1. Creation of Lists.\n"
				"2. Insertion operation.\n"
				"3. Delete operations.\n"
				"4. Search operations."
				"5. Display operations.\n"
				"6. EXIT\n"
				"================================================\n"
				);

		printf("Enter choice : ");
		scanf ("%d", &choice);
		printf("\n");

		switch (choice)	{

			case 1 :
				// if base pointer == NULL take input from user
				// Ask user for how many node at base level

				if(base_pointer != NULL){
					printf("List is already created\n");
				} else {
					printf(	
							"============================\n"
							"1.list creation at begining\n"
							"2.list creation at end\n"
							"============================\n"
						  );
					printf("Enter choice : ");
					scanf("%d", &choice_1);
					printf("Enter how many nodes : ");
					scanf("%d", &no_nodes);
	
					switch(choice_1) {
									
						case 1 :
							base_pointer = create_begin( no_nodes, base_pointer );
							printf("\n");					
							display(base_pointer);
							printf("\n");
							break;

						case 2 :
							base_pointer = create_end( no_nodes, base_pointer );
							display(base_pointer);
							break;

						default :
							attempt2--;
							printf("check choice\nAttempts remaining %d", attempt2);
					}
				}

				break;

			case 2 :		
				attempt2 = 5;
				while (attempt2) {
					printf(	
							"====================================================================\n"
							"1. Insert a value to a particular list at the beginning of the list\n"
							"2. Insert a value to a particular list at the end of the list\n"
							"3. Insert a value to a particular list after a given value in that list\n"
							"4. Insert a value to a particular list before a given value in that list\n"
							"5. Insert a value to a particular list at a given position\n"
							"6. Exit\n"
							"====================================================================\n"
							"Enter choice :  "										
					 	 );
					scanf("%d", &choice);	

					printf(
							"%d lists are avialble\n"
							"In which list want to insert?\n", getListCount(base_pointer)
					  	);
	
					scanf("%d", &list_no);
					if(list_no > 0  && list_no <= getListCount(base_pointer)) {
						// get the node of base where user wants to create list
						base_node_ref = get_base_node(list_no, base_pointer);
						data_pointer = base_node_ref -> link;
						switch(choice) {	
				
							case 1 :
								printf("Enter the data : ");
								scanf("%d", &data);
								((base_node_ref) -> link) = data_insert_begin( data, data_pointer);
								break;

							case 2 : 
								printf("Enter the data : ");
								scanf("%d", &data);
								(base_node_ref) -> link = data_insert_end( data, data_pointer );
								break;
		
							case 3 :
								printf("Enter the data : ");
								scanf("%d", &data);
								printf ("Enter the value to be searched: ");
								scanf ("%d", &value);
								position = data_after_value (data_pointer, value);
								if (position > 0) {
									(base_node_ref) -> link = data_insert_pos(data_pointer, position, data);
								} else {
									printf ("value %d is not present in th list %d\n", value, list_no);
								}
								break;

							case 4 :
								printf("Enter the data : ");
								scanf("%d", &data);
								printf ("Enter the value to be searched: ");
								scanf ("%d", &value);
								position = data_before_value (data_pointer, value);
								if (position > 0) {
									(base_node_ref) -> link = data_insert_pos(data_pointer, position, data);
								} else {
									printf ("value %d is not present in th list %d\n", value, list_no);
								}
								break;

							case 5 : 
								printf("Enter the data : ");
								scanf("%d", &data);
								printf("Enter position : ");
								scanf("%d", &position);
								(base_node_ref) -> link = data_insert_pos(data_pointer, position, data);
								break;							

							case 6 :
								attempt2 = 0;
								break;

							default :
								attempt2--;
								printf("Invalid Choice\nAttempts remaining %d\n", attempt2);
						}
									
					} else {
						attempt2--;
						printf ("Enter the list no between 0 - %d\nAttempts reamaining %d\n", getListCount (base_pointer), attempt2);
					}
				}				// break for top switch statement
				break;			
								
							
			case 3 : 
				attempt2 = 5;
				while (attempt2) {
				 	printf("%d lists are available\n", getListCount(base_pointer));
					printf("In which list you want to delete: ");
                    scanf("%d", &list_no);
 
					if(list_no > 0  && list_no <= getListCount(base_pointer)) {
						base_node_ref = get_base_node(list_no, base_pointer);
						data_pointer = base_node_ref -> link;

        	    	    printf( 
								"============================================================\n"
								" 1. Delete a  particular value in the list \n"
           	    		        " 2. Delete a node after a particular value in the list \n"
            	                " 3. Delete a node before a particular value in the list \n"
                    	        " 4. Delete first node of list \n"
                       	    	" 5. Delete last node of list \n"
                       	        " 6. Delete node at a given position in a give    n list \n"
                       	    	" 7. Delete the entire list"
								" 8. Exit\n"
								"============================================================\n"
                        	   );
                         printf("Enter choice : ");
                         scanf("%d", &choice);
                         switch(choice) {
								
							case 1:
								printf("enter a value: ");
								scanf("%d", &value);
								((base_node_ref) -> link) = data_delete_value(data_pointer, value);
								break;
                        
					        case 2: 
								printf("enter value: ");
								scanf("%d", &value);
								((base_node_ref) -> link) = data_delete_after_value(data_pointer, value);
                                break;
                                     
							case 3:
								printf("enter value: ");
								scanf("%d", &value);
								((base_node_ref) -> link) = data_delete_before_value(data_pointer, value);		
                                break;
                                    
							case 4 :
                                ((base_node_ref) -> link) = data_delete_begin( data_pointer);
                                // printf("%d", (base_node_ref-> link)-> data);
								break;
									
							case 5: 
								((base_node_ref) -> link) = data_delete_end (data_pointer);
								break;

							case 6 : 
								printf("Enter position : ");
								scanf("%d", &position);
								((base_node_ref) -> link) = data_delete_pos(data_pointer, position);
								break;
		
							case 7 : 
								((base_node_ref) -> link) = data_delete_list (data_pointer);
								break;
	
							case 8 :
								attempt2 = 0;
								break;

							default :
								attempt2--;
								printf ("Invalid Choice\nAttempts remaining %d\n", attempt2);
								break;
						}
					} else {
						attempt2--;
						printf ("Enter list no between 0 - %d\nAttempts remaining %d\n", getListCount (base_pointer), attempt2); 
					}
				}
				break;
			case 4 : /*    =================>   searching   <=============== */
 
				attempt2 = 5;
 				while (attempt2) {
					printf (   
							"===========================================\n"
                            "1. search the data in particular list\n"
                            "2. search the data in system\n"
                            "3. search the maximum in particular list\n"
							"4. search the maximum in system\n"
							"5. search the minimum in particular list\n"
							"6. search the minimum in system\n"
							"7. exit\n"
                            "Enter the choice\n"
                            "===========================================\n"
						);
					scanf ("%d", &choice);
                    switch (choice) {
 
						case 1 :
                        	printf ("%d lists are Available to search!\nIn which list you want to search: ", getListCount( base_pointer));
                            scanf ("%d", &list_no);
 
                            printf ("Enter the value to be searched: ");
                            scanf ("%d", &value);
 
                            if ((list_no > 0) && (list_no <= getListCount (base_pointer))) {
	                            base_node_ref = get_base_node (list_no, base_pointer);
                                data_pointer = base_node_ref -> link;
								if (search_val (data_pointer, &list_no, &value)) {
                                	printf ("Number of matching found %d\n",search_val (data_pointer, &list_no, &value));
								} else {
									printf ("Value %d is not fount in list %d\n", value, list_no);
                            	}
							} else {
								attempt2--;
                                printf ("Enter List no Between 1 - %d\nAttempts remaining %d\n", getListCount(base_pointer), attempt2);
                            }
							break;
 
                         case 2 :
                            printf ("Enter the value to be searched: ");
                            scanf ("%d", &value);
                            search_sys (base_pointer, &value);
							break;
													
						case 3 :
							max = 0; 
                            printf ("%d lists are Available to search!\nIn which list you want to search: ", getListCount( base_pointer));
                            scanf ("%d", &list_no);
                            if ((list_no > 0) && (list_no <= getListCount (base_pointer))) {
            	                base_node_ref = get_base_node (list_no, base_pointer);
                                data_pointer = base_node_ref -> link;
                          		max = search_max_list (data_pointer, list_no, max);
                            	printf ("Maximum value in the list %d is %d\n", list_no, max);
								search_val (data_pointer, &list_no, &max);
							} else {
								attempt2--;
								printf ("Enter List no Between 0 - %d\nAttempts remaining %d\n", getListCount (base_pointer), attempt2);
							}
							break;	

						case 4 :
							max = 0;
							max = search_max_sys (base_pointer, max);	
							printf ("Maximum value in system is %d\n", max);	
                            search_sys (base_pointer, &max);
						    break;
				
						case 5 :
							min = 0;
                            printf ("%d lists are Available to search!\nIn which list you want to search: ", getListCount( base_pointer));
                            scanf ("%d", &list_no);
                            if ((list_no > 0) && (list_no <= getListCount (base_pointer))) {
	                            base_node_ref = get_base_node (list_no, base_pointer);
                                data_pointer = base_node_ref -> link;
								min = search_max_list (data_pointer, list_no, min);
								min = search_min_list (data_pointer, list_no, min);
								printf ("Minimum value in the list %d is %d\n", list_no, min);
								search_val (data_pointer, &list_no, &min);
							} else {
								attempt2--;
								printf ("Enter List no Between 0 - %d\nAttempts remaining %d", getListCount (base_pointer), attempt2);
							}
							break;
	
						case 6 :
							min = 0;
							min = search_max_sys (base_pointer, min);
							min = search_min_sys (base_pointer, min);
							printf ("Minimum value in system is %d\n", min);
							search_sys (base_pointer, &min);
							break;

						case 7 : 
							attempt2 = 0;
							break;	

						default :
						 	attempt2--;
							printf ("Attempts remaining %d\n", attempt2);
					}
				}
											
				break;
			case 5 :
				attempt2 = 5;
				while (attempt2) {
					printf (
							"=========================\n"
							"1. Forward display\n"
							"2. Reverse Display\n"
							"3. system Display\n"
							"4. EXIT\n"
							"Enter Choice\n"
							"=========================\n"
						);
					scanf ("%d", &choice);
					switch (choice) {
		
						case 1 :
        	                printf ("%d lists are Available to search!\nIn which list you want to display: ", getListCount( base_pointer));
                            scanf ("%d", &list_no);
            	            if ((list_no > 0) && (list_no <= getListCount (base_pointer)))     {
                	            base_node_ref = get_base_node (list_no, base_pointer);
                                data_pointer = base_node_ref -> link;
								display_data_begin (data_pointer);	
							} else {
								attempt2--;
								printf ("Enter List no Between 0 - %d\nAttempts remaining %d", getListCount (base_pointer), attempt2);
							}
							printf ("\n");
							break;
				
						case 2 :
                            printf ("%d lists are Available to search!\nIn which list you want to display: ", getListCount( base_pointer));
                            scanf ("%d", &list_no);
                            if ((list_no > 0) && (list_no <= getListCount (base_pointer))) {
	                            base_node_ref = get_base_node (list_no, base_pointer);
                                data_pointer = base_node_ref -> link;
										
								display_rev (data_pointer);
							} else {
								attempt2--;
								printf ("Enter List no Between 0 - %d\nAttempts remaining %d", getListCount (base_pointer), attempt2);
							}
							printf ("\n");
							break;
	
						case 3 :
							display_system(base_pointer);
							break;
			
						case 4 :
							attempt2 = 0;
							break;
	
						default :
							attempt2--;
							printf ("Invalid choice\nAttempts remaining %d\n", attempt2);
							break;
					}
				}
				break;
		
			case 6 :
				attempt1 = 0;
				break;
		
			default :
				attempt1--; 
				printf("Invalid Choice\nAttempts remaining %d\n", attempt1);
				break;
		}
	}
		
	return 0;
}
