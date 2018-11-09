/**
*	dennis_1.c

*	AUTHOR	 				:		Murali krishna.

*	Date of creation 		:		19/9/2018.

*	purpose					:	    By this program we can calculate the sizes of 									 of different datatpes. 
*	Working procedure		:		By using operator called "sizeOf()" we are   									 calculating the size of different DataTypes.
*	Last Modified Data		:		No

--------------------------------------------------------------------------------
**/

#include<stdio.h>
#include<limits.h>

//Stdio.h contains predefined set of codes like print and scanf.

 

int main(){
	long long a;
	scanf("%lld",&a);
	int count=0;
	while(a!=0)
	{
		a=a>>1;
		count++;
	}

	printf("%f",(float)count/8);

	
}


