#include <stdio.h>
#define NAME "MURALI"
#define LASTNAME "KRISHNA"
#define age "18"

// Checking the declaration rules of macro
int main ()
{
	int *p;
	printf("%p",p);
	printf("%s ", NAME LASTNAME age);
	return 0;
}

// C
