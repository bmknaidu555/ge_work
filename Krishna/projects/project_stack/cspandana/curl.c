#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Length of username 
#define UNAME_LENGTH 100

// Length of password 
#define PASS_LENGTH 100

// Length of request
#define REQUEST_LENGTH 1000

#include "formatting.c"


int main()
{
	while(1)
	{
	FILE *fd ;
	char tryagain ;
	char *temp_buffer ;
	printf("\n\n ---------  Welcome to Cspandana  ---------\n\n");
	
	char *username = NULL ;
	char *password = NULL ;
	char *request = NULL ;
	char LOGIN_URL[] = "https://spandana.globaledgesoft.com/WebServiceLogin.asmx/validateUser";
	
	username = ( char * ) malloc ( UNAME_LENGTH * sizeof (char) );
	password = ( char * ) malloc ( PASS_LENGTH * sizeof (char) );	
	request = ( char * ) malloc ( REQUEST_LENGTH * sizeof (char) );
	
	__fpurge(stdin);

	printf ("\nUsername : ");
	fgets (username, 99, stdin) ;
	
	__fpurge(stdin);

	printf ("\nPassword : ");
	system ("stty -echo");
	fgets (password, 99, stdin) ;
	system ("stty echo");
	request = format_data ("curl -X POST -H" 
						          " 'Content-Type: application/json'"
                                  " -c cookie" 
                                  " -d '{\"username\":\"%s\",\""
                                           "password\":\"%s\""
									  "}' %s > response.txt 2> error.txt",
										 username, password, LOGIN_URL);
	system(request);
	system("grep true response.txt > grepresult.txt");
	fd = fopen("grepresult.txt", "r");

	if(fd != NULL)
	{
		temp_buffer = malloc(50);
		
		__fpurge(stdin);		

		fgets(temp_buffer, 50,fd);

		if(strlen(temp_buffer) > 0)
		{
			printf("\nLogin Success ... Redirecting to TimeSheet ... \n");
			break;
		}
		else
		{
			printf("\nLogin Failed ... Do you want to Try Again?(Y/N) \n");
			
			if(fgetc (stdin) == 'Y')
				continue;
			else 
				 break;
		}	
	}
		
	free (username);
	free (password);	
	free (temp_buffer);
	}
}	
