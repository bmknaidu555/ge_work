#include "header.h"

int config_cui()
{
	char buffer[BUFFER_SIZE];
	system("clear");
	
	printf("\b\b\b\b\b\bEntering into configuration Mode\n");
	printf("Type \"help\" to view command list\n");
	
	while(1){
		__fpurge(stdin);
		printf("(config) > ");
		fgets(buffer, BUFFER_SIZE, stdin);
		printf("%s", buffer);	
		
		if(strncmp ("help", buffer, 4) == 0){
			printf( "ls - To list the configuration info\n"
					"set <config_name> = <value> - To set the configuration\n"
				  );
		}
		else
			printf("Type \"help\" to view command list\n");
		printf("\n"); 
			
	}
}






