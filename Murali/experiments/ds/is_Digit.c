#include<stdio.h>
int *is_integer()
{
	char *input = (char *) malloc(sizeof(char) * 100);
    charmemVal(input);
    __fpurge(stdin);
    fgets(input, 100, stdin);

	int *total = (int*) malloc( sizeof(int) );
	charmemVal(total);
	
	if(*input == '\0' )
		return NULL;

	 if( *input  == '\n')
		return NULL;
	

	// check for initial spaces
	for( ; is_space( *input ); input++);
	
	// check weather is there any sign precede before number 
	// eg : +234 or -345
	if (*input == '-' || *input == '+')
		input++;

	// iterate until reaching to newline or end of string.
	while ( *input != '\n' && *input != '\0' ){	
	
		// if it is not a digit enter into block
		if( !is_digit( *input ) ) {
					 
			if(is_space (*input)) {
			
			// check weather is there any spaces at ending
			//eg : 23<space><space>......

				// check weather it had spaces till end of string 
				while( *input == ' ' ) 
					input++;
			
				if ( !(*input  == '\n'))
					return NULL;
				else
					continue;	
			
			} else 	
				return NULL;	
		}
		*total = (*total * 10) + (*input - 48);
	   	input++;
	}
	return total;
}
