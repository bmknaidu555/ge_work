#include <stdlib.h>
int main()
{
	int *list;
	int size;

	printf("Enter the list size : ");
	scanf("%d",&size);

	list =(int *) malloc(size *sizeof(int));
	printf("Enter Array elements :");

	// iscanf() reads the array elements from user(stdin)	
	iascanf(list, size);

	// sort the data.
	selection_sort(list ,size);	

	printf("The sorted List is : ");

	// iaprintf prints the array by taking array pointer and size as params
	iaprintf(list, size);
}

int insertion_sort(int *list, int size)
{
	int temp;
	int i = 0,j = 0;

	for(i = 0; i < size-1; i++){
		if(list[i] > list[i+1])		
		{
			for(j = (i+1); j>0; j--)
			{
				if(list[j] < list[j - 1])
				{
					temp = list[j];
					list[j] = list[j-1];
					list[j-1] = temp; 
				}
				else 
					break;
			}
		}
	}
}
