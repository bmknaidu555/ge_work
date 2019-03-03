#include "header.h"

int initiate_call(void)
{
	char *input_buffer;

	/* start line stuctures  */

	PACKET *packet = NULL;

	/* message header fields structures */
	
	MSGHDR *message_header;
	CALLID *callid;
	

	/* initialize all the structures */
	init_packet(&packet);
	init_startline(packet, request_line);
	init_message_hddr(packet, 10, call_id, contact, content_length,
							content_type, cseq, from, max_forward,
							to, user_agent, via);
	
	
	STRTLINE *startline_ref = NULL;
	REQLINE	*reqline_ref = NULL;
	REQURI *requri_ref = NULL;
	SIPURI *sipuri_ref = NULL;


	startline_ref = packet -> start_line;				
	reqline_ref  = startline_ref -> req_line;  		
	requri_ref = reqline_ref -> request_uri;	
	sipuri_ref = requri_ref -> sip_uri; 
	
	reqline_ref -> method_name = "REGISTER";
	/* Registrar domain */
	sipuri_ref -> host_port = "117.254.87.117";
	//sread (sipuri_ref -> host_port, BUFFER_SIZE);
	reqline_ref -> version = "SIP/2.0";
	
		

		
}
