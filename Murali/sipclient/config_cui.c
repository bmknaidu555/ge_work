#include "header.h"
void display_config (void);
int config_cui()
{
	char buffer[BUFFER_SIZE];

	system("clear");	
	printf("Entering into configuration Mode\n");
	printf("Type \"help\" to view command list\n");
	
	while(1) {
	
		__fpurge(stdin);
		printf("(config) > ");
		fgets(buffer, BUFFER_SIZE, stdin);
		
		if(strncmp ("help", buffer, 4) == 0) {
			printf( "ls - To list the configuration info\n"
					"set <config_name> = <value> - To set the configuration\n"
				  );
		} else if(strncmp("exit", buffer, 4) == 0) {
			printf("Exiting configuration...\n\n");
			return 0;
		} else if(strncmp ("ls", buffer, 2) == 0) {
			display_config();
		}else {
			printf("Invalid Command!! Type \"help\" to view command list\n");	
			printf("\"%s\"", buffer );
		}
	}
}


void display_config(void)
{
	printf("\n");
	printf(" <config_name> = <value>\n ======================== ");
	printf("\n");
	/* display all the configuration info in config file */
	int i = 0;	
	FILE *fp =  NULL;		
	char *temp_ptr = NULL;
	char *buffer = (char *) alloc_memory(INPUT_BUFFER);	
	
	fp = fopen("config.cfg", "r");
	
	for(temp_ptr = buffer; 
			fgets(buffer, INPUT_BUFFER, fp) != NULL; i = 0) {		
		if(buffer[i] == '#' || buffer[i] == '\n') 
			continue;	
		while(buffer[i] != '=') {
			i++;
		}	
		
		buffer[i++] = '\0';
		printf(" %s = %s", temp_ptr, &buffer[i]);
	}
	
	/* if fgets returns NULL & its not EOF then log the error */
	if(!feof(fp)) {
		printf("some error came..\n");
		exit(EXIT_FAILURE);
	}
	printf("\n");	

}


