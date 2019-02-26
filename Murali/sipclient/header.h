#include <stdio.h>
#include <stdlib.h>
#include "packet.h"
#include <stdargs.h>
/* Buffer to store the user input */
#define BUFFER_SIZE 200
/* Maximum size of method name */ 
#define MAX_METHOD_SIZE 25
#define SIP_VERSION_SIZE 10
/* Maximum username size */
#define USER_INFO_SIZE 100
#define HOST_INFO_SIZE 100

/* not defined yet */
#define URI_PARAM_SIZE 100

/* API to initate a call */
int initiate_call(void);

/* API to allocate memory */
/* The below API use */

void *alloc_memory(size_t size);
void dumplog(const char* message, const char* fun_name, 
					const char* file_name, const int line_no);


int setmethod_name (char *buffer, const char* method_name);

/* see SIPURI structure for more details */
/* input contains : username@host:port */
/* Below API will split the data and fill into the structure */
int setsip_uri (SIPURI sipuri_ref, const char *input);

