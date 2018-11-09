#include "../HEADER/header.h"

void bubble_sort(long *list, unsigned long size)
{
	int temp;
	unsigned long i = 0;
	unsigned long j = 0;

	for(i = 1; i < size; i++){
		for(j = 0; j < (size - i); j++){
			if(list[j] > list[j+1]){
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;	
				printf("header\n");		
			}
		}	
	}

}
