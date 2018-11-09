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

void memVal(struct base_node *);
void  display (struct base_node *);
struct base_node *create();
struct base_node *create_begin(int, struct base_node *);
struct base_node *create_end(int, struct base_node *);
struct data_node *create_data(int);
struct data_node *data_insert_begin(int, struct data_node *);
struct data_node *data_insert_end(int, struct data_node *);

int data_after_value (struct data_node *, int);
int data_before_value (struct data_node *, int);

struct data_node *data_insert_pos(struct data_node *, int, int);
struct data_node *data_delete_begin (struct data_node *);
struct data_node *data_delete_value (struct data_node *, int);
struct data_node *data_delete_end (struct data_node *);
struct data_node *data_delete_pos(struct data_node *, int);
struct data_node *data_delete_after_value (struct data_node *,int);
struct data_node *data_delete_before_value (struct data_node *,int);
struct data_node *data_delete_list(struct data_node *);

int getNodeCount(struct data_node *);
int getListCount(struct base_node *);

struct base_node *get_base_node(int, struct base_node *);

void display_data_begin(struct data_node *);
void display_rev (struct data_node *);
void display_system(struct base_node *);

int search_pos(struct data_node *, int);
int search_val (struct data_node *, int *, int *);
void search_sys (struct base_node *, int *);
int search_max_list (struct data_node *, int, int);
int search_min_list (struct data_node *, int, int);
int search_min_sys (struct base_node *, int);
int search_max_sys (struct base_node *, int);