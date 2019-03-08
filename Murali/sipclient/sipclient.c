#include "header.h"

int main(int argc, char argv[])
{
	/* Function Pointer to call the respected modules */
	int (*caller)(void);
	/* Initializing buffer with modules */
	void *modules[] = {initiate_call, config_cui};
	char choice;
	
	printf("1.CALL\n2.VIEW CONFIGURATION\n2.EXIT\n");
	choice = fgetc(stdin);
	caller = modules[choice - 49];	
	
	/* Choice == 1 intitate CALL module */
	/* Choice == 2 exit */
	caller();
	
	return 0;
}
