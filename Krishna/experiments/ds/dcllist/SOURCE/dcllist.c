#include <stdio.h>
#include <stdlib.h>

// create node structure for base_list
struct base_node
{
		struct base_node *prev ;		
		struct data_node *link ;
		struct base_node *next ;
};

//create node structure for data_list
struct data_node
{
		struct data_node *prev ;
		int data;
		struct data_node *next ;		
};

void memVal(struct base_node * temp)
{
		if(temp == NULL){	
				perror ("Memory Allocation Failure");
				exit (EXIT_FAILURE);
		}
}

struct base_node *create()
{
		struct base_node *temp;
		temp = (struct base_node *) malloc( sizeof(struct base_node) );
		temp -> prev = temp;
		temp -> next = temp;
		temp -> link = NULL;
		return temp;
}

void  display (struct base_node *base_pointer)
{
		if(base_pointer == NULL){
				printf ("List is empty");
				return;
		}

		struct base_node *temp = base_pointer;

		printf ("[ ");
		printf("%p -->",base_pointer -> link);
		base_pointer = base_pointer -> next;

		while (base_pointer != temp) {
	            printf ("%p", base_pointer -> link);
				base_pointer = base_pointer -> next;
				printf("--> ");

		}

		//printf Data formatting for clear understanding
		printf ("null ");
		printf ("]");	

}



struct base_node *create_begin(int count, struct base_node *base_pointer )
{
		int i;

		if(base_pointer == NULL)
				base_pointer = create();

		struct base_node * temp = NULL;
		for(i = 1; i < count; i++)
		{
				temp = create();
				// point previous of start node to end node
				temp -> prev = base_pointer -> prev ;
				// point next of end node to start node
				(temp -> prev) -> next = temp;
				// point base_pointer prev to temp node
				base_pointer -> prev = temp;
				// 	temp next base_pointer
				temp -> next = base_pointer;
				base_pointer = temp; 
		}
		return base_pointer;
}


struct base_node *create_end(int count, struct base_node *base_pointer)
{	
		int i;

		if(base_pointer == NULL)
				base_pointer = create();

		struct base_node * temp = NULL;
		for(i = 1; i < count; i++)
		{
				temp = create();
				// point previous of start node to end node

				temp -> prev = base_pointer -> prev;
				(temp -> prev) -> next = temp;
				base_pointer -> prev = temp;
				temp -> next = base_pointer;
		}
		return base_pointer;


}

struct data_node *create_data(int data)
{
	struct data_node *temp = NULL;
	temp = (struct data_node *) malloc(sizeof (struct data_node) );
	temp -> data = data;
	temp -> prev = temp;
	temp -> next = temp;
	return temp;
}

struct data_node *data_insert_begin(int data, struct data_node *data_pointer)
{
	if(data_pointer == NULL)
		return create_data( data );

		struct data_node *temp = NULL;
		temp = create_data(data);
		// point previous of start node to end node
		temp -> prev = data_pointer -> prev ;
		// point next of end node to start node
		(temp -> prev) -> next = temp;
		// point base_pointer prev to temp node
		data_pointer -> prev = temp;
		// 	temp next base_pointer
		temp -> next = data_pointer;
		data_pointer = temp; 
		printf("%d",data_pointer -> data);

		return data_pointer;
}

struct data_node *data_pos(
							int data,
							struct data_node *data_pos,
							struct  
						  )
{
		
}


struct data_node *data_insert_end(int data, struct data_node *data_pointer)
{
	if(data_pointer == NULL)
			return create_data( data );

	struct data_node * temp = NULL;
	temp = create_data(data);
	// point previous of start node to end node
	temp -> prev = data_pointer -> prev ;
	// point next of end node to start node
	(temp -> prev) -> next = temp;
	// point base_pointer prev to temp node
	data_pointer -> prev = temp;
	// 	temp next base_pointer
	temp -> next = data_pointer; 
return data_pointer;

}
 struct data_node *data_delete_begin (struct data_node * data_pointer)
 {
	 struct data_node *temp = NULL;
	 struct data_node *temp1 = NULL;
     temp = data_pointer -> next;
	temp1 = data_pointer;
   	
	 if(data_pointer == NULL)
         printf("List is empty");
     else if((data_pointer -> next) == data_pointer) {
		data_pointer = NULL;
		return data_pointer;
	 } else {
 		temp -> prev = data_pointer -> prev;
		(data_pointer -> prev) -> next = temp;
		data_pointer = temp;
		free(temp1);
    }
     return data_pointer;
 }

struct data_node *data_delete_end (struct data_node *data_pointer)
{
	 struct data_node *temp = NULL;
	if(data_pointer == NULL){
		printf("List is empty");
	}

	else if(data_pointer -> prev == data_pointer ){
		data_pointer = NULL;
		return data_pointer;
	}
	
	else {
		temp = data_pointer -> prev;
		(temp -> prev) -> next = data_pointer;
		data_pointer -> prev = temp -> prev;
		}
	return data_pointer;
}

struct data_node *data_delete_pos(struct data_node *data_pointer, int pos){
	if(data_pointer == NULL)
		printf("List is empty");
	//else 	

}

int getListCount(struct base_node *base_pointer)
{
	if(base_pointer == NULL)
		return 0;
	
	int count = 1;
	struct base_node *temp = base_pointer;
	base_pointer = base_pointer -> next;

	while(base_pointer != temp){
		count++;
		base_pointer = base_pointer -> next;
	}

	return count;
}

struct base_node *get_base_node(int count, struct base_node *base_pointer)
{
	while( count-- != 1)
	{
		base_pointer = base_pointer -> next;
	}
	return base_pointer;	
}

void display_data_begin(struct data_node *data_pointer)
{
	struct data_node *temp = data_pointer;
	
	if(data_pointer == NULL)
	{
		printf("NULL");
		return;
	} 


	printf ("[ ");
	printf("%d ", data_pointer -> data);	
	data_pointer = data_pointer -> next;
		
		
		while (data_pointer != temp) {
	            printf ("%d ", data_pointer -> data);
				data_pointer = data_pointer -> next;

		}

		//printf Data formatting for clear understanding
		printf ("]");	
}


void display_system(struct base_node *base_pointer)
{
	int i = 0;
	int base_count = getListCount(base_pointer);
	for(i = 1; i <= base_count ;i++ )
	{
		printf("\n\n\n\nList %d : \n\n", i);
		display_data_begin(base_pointer -> link );
		base_pointer = base_pointer -> next;
		printf("\n===============================================\n");	
	}
	
}

int search_val (struct data_node *data_pointer, int *list_no, int *value)
 {
     struct data_node *temp = NULL;
     int node = 0;
     int count = 0;
     if (data_pointer == NULL) {
         printf ("List %d is empty\n", *list_no);
     } else {
         temp = data_pointer;
 
         printf("In list %d - %d is available at ",*list_no, *value);
         do {
             node = node + 1;
             if ((temp -> data) == *value) {
             printf (" node %d",  node);
             count++;
             }
             temp = temp -> next;
         } while (temp != data_pointer);
         printf ("\n");
     }
     if (count == 0)
         return 0;
     else
         return count;
 }

void search_sys (struct base_node *base_pointer, int *value)
 {
     int count = 1;
     struct data_node *data_pointer = NULL;
     struct base_node *base_node_ref = NULL;
     while (count <= getListCount (base_pointer)) {
         base_node_ref = get_base_node (count, base_pointer);
         data_pointer = base_node_ref -> link;
         printf ("Number of matching in list %d is %d\n\n", count, search_val (data_pointer, &count, value));
         count++;
     }
 }

int main ()
{
		// handler to the base list 0
		struct base_node *base_pointer = NULL;

		// handler to the data list in level 1
		struct data_node *data_pointer = NULL;
		int temp;
		struct base_node *base_node_ref = NULL;

		int choice_1;

		struct node *head = NULL;
		int choice;
		int data;
		int list_no;
		int position;
		int value;
		while(1)
		{
				printf (	"================================================\n"
							"\n1. Creation of Lists.\n2. Insertion operation."
							"\n3. Delete operations.\n4. Search operations."
							"\n5. Display operations.\n6. EXIT\n"
							"================================================\n"
					   );

				printf("Enter choice : ");
				scanf ("%d", &choice);
				printf("\n");

				switch (choice)
				{
						case 1 :
								// if base pointer == NULL take input from user
								// Ask user for how many node at base level

								if(base_pointer != NULL){
										printf("List is already created\n");
								} else {

										int no_nodes;					
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

										switch(choice_1)
										{
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
														printf("check choice");
										}


								}

								break;
						case 2 :
				
								
								printf(
										"%d lists are avialble\n"
										"In which list want to insert?\n", getListCount(base_pointer)
									  );
	
								scanf("%d", &list_no);

								if(list_no > 0  && list_no <= getListCount(base_pointer))
								{
									// get the node of base where user wants to create list
									base_node_ref = get_base_node(list_no, base_pointer);
									data_pointer = base_node_ref -> link;
											
									printf(	
											"====================================================================\n"
											"1. Insert a value to a particular list at the beginning of the list\n"
											"2. Insert a value to a particular list at the end of the list\n"
											"3. Insert a value to a particular list after a given value in that list\n"
											"4. Insert a value to a particular list before a given value in that list\n"
											"5. Insert a value to a particular list at a given position\n"
											"====================================================================\n"
											"6. Enter choice :  "
										
										  );
									scanf("%d", &choice);	

									printf("Enter the data : ");
									scanf("%d", &data);

									switch(choice)
									{	
									
										case 1 :
												((base_node_ref) -> link) = data_insert_begin( data, data_pointer);
												break;
										case 2 : 
												(base_node_ref) -> link = data_insert_end( data, data_pointer );
												break;									

										default :
												printf("Invalid Choice");

									
									
									}				// break for top switch statement
							break;			
								
							
						case 3 :  printf("%d list    s are available", getListCount(base_pointer    ));
                             printf("In which list you want to delete?");
                             scanf("%d", &list_no);
 
                                 base_node_ref = get_base_node(list_no, base_pointer);
                                 data_pointer = base_node_ref -> link;
 
                                 printf( "============================================================="
										 " 1. Delete a node after a particular value in     the list \n"
                                         " 2. Delete a node before a particular value i    n the list \n"
                                         " 3. Delete first node of list \n"
                                         " 4. Delete last node of list \n"
                                         " 5. Delete node at a given position in a give    n list \n"
                                         " 6. Delete the entire list"
										 "============================================================"
                                       );
                                 printf("\n\n Enter choice : ");
                                 scanf("%d", &choice);
                                 switch(choice)
                                 {
                                     case 1: 
									//	printf("enter value\n");
									//	scanf
                                         break;
                                      case 2:
                                         break;
                                     case 3 :
                                         ((base_node_ref) -> link) = data_delete_begin( data_pointer);
                                    //  		printf("%d", (base_node_ref-> link)-> data);
										   break;
									case 4: 
										((base_node_ref) -> link) = data_delete_end (data_pointer);
										break;
									case 5 : 
										printf("Enter position : ");
										scanf("%d", &position);
										((base_node_ref) -> link) = data_delete_pos(data_pointer, position);
										break;
								}
								break;
						case 4 : /*    =================>   searching   <=============== */
 
                                 printf (    "======================================\n"
                                             "1. search the data in particular list\n"
                                             "2. search the data in system\n"
                                             "3. exit\n"
                                             "Enter the choice\n"
                                             "======================================\n"
                                         );
                                 scanf ("%d", &choice);
 
                                     switch (choice) {
 
                                         case 1 :
                                                 printf ("%d lists are Available to search!\nIn which list you     want to search\n", getListCount( base_pointer));
                                                 scanf ("%d", &list_no);
 
                                                 printf ("Enter the value to be searched  :   ");
                                                 scanf ("%d", &value);
 
                                                 if ((list_no > 0) && (list_no <= getListCount (base_pointer)))     {
                                                     base_node_ref = get_base_node (list_no, base_pointer);
                                                     data_pointer = base_node_ref -> link;
                                                     printf ("Number of matching found %d\n",search_val (data_pointer, &list_no, &value));
                                                 } else {
                                                      printf ("\nEnter List no Between 1 - %d", getListCount(base_pointer));
                                                 }
                                                 break;
 
                                         case 2 :
                                                 printf ("Enter the value to be searched   :   ");
                                                 scanf ("%d", &value);
                                                 search_sys (base_pointer, &value);
                                                 break;
                                 }
	
								break;
						case 5 :
								display_system(base_pointer);
								break;

						default : 
								printf("Invalid Choice");
				}

		}}
return 0;
}
