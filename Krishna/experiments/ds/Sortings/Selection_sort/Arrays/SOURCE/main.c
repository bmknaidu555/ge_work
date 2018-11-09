
#include "../HEADER/header.h"

int main()
{
	long *list;
	unsigned long size;

	printf("Enter the list size : ");
	scanf("%ld",&size);

	list =(long *) malloc(size * sizeof(long));
	printf("Enter Array elements :");

	/* iscanf() reads the array elements from user(stdin)	*/
	iascanf(list, size);

	/*  sort the data.  */
	selection_sort(list ,size);	

	printf("The sorted List is : ");
	// iaprintf prints the array by taking array pointer and size as params
	iaprintf(list, size);
	return 0;
}
