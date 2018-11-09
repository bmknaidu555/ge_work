#include "../HEADER/header.h"

/* 	low points to the starting element-1 in  the list
	high points to the ending element in the list
*/
 // for 5 elements low = -1 and high = 4
void quick_sort(long low, long high, long *list)
{
	if(low < high) {

		int i, j;
		i = low;

		long pivot = high;
		for(j = low + 1; j <= high; j++) {
			if(list[j] <= list[pivot]) {
				i++;	
				swap(&list[i], &list[j]);
			}	
		}

		pivot = i;
		// left side
		quick_sort(low, pivot - 1, list);
		// right side
		quick_sort(pivot, high, list);
	}
	else
 		return;
}
