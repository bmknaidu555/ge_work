#include "../HEADER/header.h"

void merge_sort(long *list, long size)
{
	int i = 0;
	if(size < 2)
		return;

	long mid = 	size / 2;
	// Allocate memory for left array.
	long left[mid];
	for(i = 0; i < mid; i++)
		left[i] = list[i];

	// allocating memory for rigth array.
	long right[size - mid];
	for(i = mid; i < size; i++)
		right[i - mid] = list[i];

	merge_sort(left,mid);
	merge_sort(right,(size - mid));
	merge(left, right, mid, (size - mid), list); 	
}

void merge(long *left, long *right,long l_size, long r_size, long *list)
{
	long i = 0;
	long j = 0;
	long k = 0;

	while(i < l_size && j < r_size) {
		if(left[i] < right[j]){
			list[k] = left[i];
			i++;
			k++;
		} else {
			list[k] =right[j];
			j++;
			k++;
		}
	}

	while(i < l_size){
		list[k] = left[i];
		i++;
		k++;
	}	

	while(j < r_size)
	{
		list[k] = right[j];
		j++;
		k++;
	}

}
