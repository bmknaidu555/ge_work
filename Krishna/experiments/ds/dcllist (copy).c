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

		int count = 6;

		while (base_pointer != temp) {
				printf ("%p", base_pointer -> link);
				base_pointer = base_pointer -> next;
				printf("--> ");

		}

		//printf Data formatting for clear understanding
		printf ("null ");
		printf ("]");	
		printf ("\n%19c\n%19c\n%19c\n\n%21s",'^','|','|',"head");

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
		return data_pointer;
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
	data_pointer = temp; 
	return data_pointer;

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
	while( count-- != 0)
		base_pointer = base_pointer -> next;

	return base_pointer;	
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
		while(1)
		{
				printf (
								"\n1. Creation of Lists.\n2. Insertion operation."
								"\n3. Delete operations.\n4. Search operations."
								"\n5. Display operations.\n6. EXIT\n"
					   );

				printf("Enter choice : ");
				scanf ("%d", &choice);

				switch (choice)
				{
						case 1 :
								// if base pointer == NULL take input from user
								// Ask user for how many node at base level

								if(base_pointer != NULL){
										printf("List is already created");
								} else {

										int no_nodes;					

										printf("1.list creation at begining\n2.list creation at end\n");
										scanf("%d", &choice_1);

										printf("Enter how many nodes");
										scanf("%d", &no_nodes);

										switch(choice_1)
										{
												case 1 :
														base_pointer = create_begin( no_nodes, base_pointer );
														display(base_pointer);
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
										"In which list want to insert?", getListCount(base_pointer)
									  );
	
								printf("In which list u want to insert");
								scanf("%d", &list_no);

								if(list_no > 0  && list_no <= getListCount(base_pointer))
								{
									// get the node of base where user wants to create list
									base_node_ref = get_base_node(list_no, base_pointer);
									data_pointer = base_node_ref -> link;
											
									printf(		"1. Insert a value to a particular list at the beginning of the listi\n"
												"2.	Insert a value to a particular list at the end of the list\n"
												"3. Insert a value to a particular list after a given value in that list\n"
												"4. Insert a value to a particular list before a given value in that list\n"
												"5. Insert a value to a particular list at a given position\n"
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

									}
									
							}
							// break for top switch statement
							break;			
								
							
						case 3 : 
								break;
						case 4 :	
								break;

						default : 
								printf("Invalid Choice");
				}

		}
return 0;
}
