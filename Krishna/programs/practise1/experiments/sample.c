#include<stdio.h>

int main()
{
	int arr[3][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};

	int **p = (int**)arr;
	//int **p = arr;
	
	//printf("%d\n",    *(*p+1)) ;
	printf("%d %d\n",p[0][0],arr[0][0]);
	return 0;
}
