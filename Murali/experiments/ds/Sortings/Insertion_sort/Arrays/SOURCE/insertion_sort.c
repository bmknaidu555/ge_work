#include "../HEADER/header.h"

void insertion_sort(long *list, unsigned long size)
{
	unsigned long i = 0;
	unsigned long key = 0;
	long temp;

	for(i = 0; i < size - 1; i++) {	
		for(key = i+1; key > 0; key--) {
			if(list[key] < list[key - 1]) {	
				temp = list[key];
				list[key] = list[key - 1];
				list[key - 1] = temp; 
			}	else 
					break;
		}	
	}
}
