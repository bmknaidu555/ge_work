#include <stdio.h>
#include <stdlib.h>
#include "packet.h"
#include <stdarg.h>

/* Buffer to store the user input */
#define BUFFER_SIZE 200
#define INPUT_BUFFER 1500
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
int config_cui(void);


int init_packet (PACKET **packet);

int init_startline (PACKET *packet, int (*fun_ptr)(STRTLINE *startline_ref));
int request_line (STRTLINE *startline_ref);
int response_line (STRTLINE *startline_ref);

/* packet initialization fields */
int init_message_hddr (PACKET *packet, unsigned int count, ...);
int accept (MSGHDR *messageheader_ref);
int call_id (MSGHDR *messageheader_ref);
int contact (MSGHDR *messageheader_ref);
int content_length (MSGHDR *messageheader_ref);
int content_type (MSGHDR *messageheader_ref);
int cseq (MSGHDR *messageheader_ref);
int from(MSGHDR *messageheader_ref);
int max_forward(MSGHDR *messageheader_ref);
int to(MSGHDR *messageheader_ref);
int user_agent(MSGHDR *messageheader_ref);
int via(MSGHDR *messageheader_ref);

/* packet filling API's */

/*	start line */
void fill_start_line(PACKET *packet, const char *method_name, 
						const char *host, const char *sip_version);
/* accept */
void accept(void);
void 


/* Config API's  */

void display_config (void);



/* 	Custom I/O functions 	*/

/* Allocate memory & pass the buffer & file pointers and size */
char *fsread(char *buffer, size_t buffer_size , FILE *ptr);




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

