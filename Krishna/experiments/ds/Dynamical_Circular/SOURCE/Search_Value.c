#include "../HEADER/header.h"

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
