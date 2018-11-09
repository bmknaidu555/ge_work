#include <stdio.h>
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

int selection_sort(int *list, int size)
{
	int temp;
	int i = 0,j = 0;

	for(i = 0; i < size-1; i++){
		for(j = i; j < size - 1; j++){
			if(list[i] > list[j+1]){
				temp = list[i];
				list[i] = list[j+1];
				list[j+1] = temp;			
			}
		}	
	}

}
