#include "../HEADER/header.h"

int getNodeCount(struct data_node *data_pointer)
 {
     if(data_pointer == NULL)
         return 0;
 
     int count = 1;
     struct data_node *temp = data_pointer;
     data_pointer = data_pointer -> next;
 
     while(data_pointer != temp){
         count++;
         data_pointer = data_pointer -> next;
     }
 
     return count;
 }
