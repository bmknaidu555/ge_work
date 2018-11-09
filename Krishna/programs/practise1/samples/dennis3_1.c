#include<stdio.h>


int search(int, int, int ,int[]);

int main()
{
	int a[]={1,2,3,4,5,6,7};
	int key;
	scanf("%d",&key);
	if(search(key,0,6,a))
		printf("I found the number\n");
	else
		printf("I cant found the numbner\n");
	return 0;	
}

int search(int key, int low, int high, int list[])
{
	int mid = (low + high) / 2;
 
	while(low <= high && list[mid]!=key)
	{
		if(list[mid]>key)
			high = mid-1;
		else
			low = mid + 1;
	
		mid = (low + high) / 2;	
	}

	if(low>high)
		return 0;
	else
		return 1;
	
}

