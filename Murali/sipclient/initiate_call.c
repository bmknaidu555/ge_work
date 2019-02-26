#include "header.h"

int initiate_call(void)
{
	char *input_buffer;

	/* start line stuctures  */

	PACKET *packet = NULL;
	STRTLINE *startline_ref = NULL;
	REQLINE	*reqline_ref = NULL;
	REQURI *requri_ref = NULL;
	SIPURI *sipuri_ref = NULL;

	/* message header fields structures */
	
	MSGHDR *message_header;
	CALLID *callid;
	



	/* initialize all the structures */
	init_packet(&packet);
	init_startline(packet, request_line);
	init_message_hddr(packet, 10, call_id, contact, content_length,
							content_type, cseq, from, max_forward,
							to, user_agent, via, NULL);
	



	/* Create individual references for all structures */
	
	printf("%p\n", packet);	
	startline_ref = packet -> start_line;				
	reqline_ref  = startline_ref -> req_line;  		
	requri_ref = reqline_ref -> request_uri;	
	sipuri_ref = requri_ref -> sip_uri; 

		
	input_buffer = (char *) alloc_memory (sizeof (BUFFER_SIZE));	

/*
	============================================================
	Request_Line
*/
	/* Method name */
	reqline_ref -> method_name = "REGISTER";
	/* Request URI */
	//printf("Enter registrar or proxy domain\n");
	sipuri_ref -> host_port = "117.254.87.117";
	//sread (sipuri_ref -> host_port, BUFFER_SIZE);
	/* Version */
	reqline_ref -> version = "SIP/2.0";
	
/* 
	============================================================
	Message Header
	
		




*/	

	

		
}
