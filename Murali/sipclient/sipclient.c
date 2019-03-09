#include "header.h"

int main(int argc, char argv[])
{
	/* Function Pointer to call the respected modules */
	int (*caller)(void);
	/* Initializing buffer with modules */
	void *modules[] = {initiate_call, config_cui, exit};
	char choice;
	while(1){	
		__fpurge(stdin);
		printf("1.Call\n2.Configuration\n3.Exit\n");
		choice = fgetc(stdin);
		caller = modules[choice - 49];	
		caller();
	}
	
	return 0;
}
