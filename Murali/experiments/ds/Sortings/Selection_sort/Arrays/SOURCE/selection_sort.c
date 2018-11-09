#include "../HEADER/header.h"

void selection_sort(long *list, unsigned long size)
{
	unsigned long i = 0;
	unsigned long j = 0;
	unsigned long pointer = 0;
	unsigned long temp;

	for(i = 0; i < size - 1; i++){
		pointer = i;
		printf("-------------- main\n");
		for(j = i+1; j < size; j++){
			printf("inner\n");
			if(list[pointer] > list[j])
				pointer = j;
			temp = list[pointer];
			list[pointer] = list[i];
			list[i] = temp; 
		}	
	}

}
