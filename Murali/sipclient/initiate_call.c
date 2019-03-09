#include "header.h"

int initiate_call(void)
{
	printf("Calling mode initiated...\n");
	char *input_buffer;

	/* start line stuctures  */
	PACKET *packet = NULL;

	/* message header fields structures */
	MSGHDR *message_header = NULL;
	
	/* initialize all the structures */
	init_packet(&packet);
	init_startline(packet, request_line);
	init_message_hddr(packet, 10, call_id, contact, content_length,
							content_type, cseq, from, max_forward,
							to, user_agent, via);
	
/* Message header */

	MSGHDR *messageheader_ref = NULL;
	messageheader_ref = packet -> msg_hddr;

	CONTACT *contact_ref = messageheader_ref -> contact;
	/* contactparam */ 
	CONTACTPARAM *contactparam_ref = contact_ref -> cont_param;	
	/* 	->	nameaddr */
	NAMEADDR *nameaddr_contact_ref = contactparam_ref -> name_addr;
	nameaddr_contact_ref -> display_name = "murali krishna";
	/*		-> addrspec */
	ADDRSPEC *addrspec_contact_ref = nameaddr_contact_ref -> addr_spec;
	addrspec_contact_ref -> user_info = "murali";
	addrspec_contact_ref -> host_part = "172.16.5.148";
	addrspec_contact_ref -> uri_param = "NULL";
	
	/*	-> contactparams */
	CONTACTPARAMS *contactparams_ref = contactparam_ref -> cont_params;
	contactparams_ref -> expires = NULL;

/* Content length */

	messageheader_ref -> content_length = "0";

/* Cseq */

	CSEQ *cseq_ref = messageheader_ref -> cseq;
	cseq_ref -> cseq_no = "1";
	cseq_ref -> method_name = "REGISTER";

/* Max-forwards */

	messageheader_ref -> max_forwards = "70";

/* From */

	FROM *from_ref = messageheader_ref -> from;
	/* nameaddr */
	NAMEADDR *nameaddr_from_ref = contactparam_ref -> name_addr;
	nameaddr_from_ref -> display_name = "murali krishna";
	/*addrspec */
	ADDRSPEC *addrspec_from_ref = nameaddr_from_ref -> addr_spec;
	addrspec_from_ref -> user_info = "murali";
	addrspec_from_ref -> host_part = "172.16.5.148";
	addrspec_from_ref -> uri_param = "NULL";
	/* fromparams */
	FROMPARAMS *fromparams_ref = from_ref -> from_params;	
	fromparams_ref -> tag = "34h3jkh2k34b3k234j34h4bk2lvvg23"; 

/* To */
	
	TO *to_ref = messageheader_ref -> to;
	/* namaddr */
	NAMEADDR *nameaddr_to_ref = contactparam_ref -> name_addr;
	nameaddr_to_ref -> display_name = "murali krishna";
	/*addrspec */
	ADDRSPEC *addrspec_to_ref = nameaddr_to_ref -> addr_spec;
	addrspec_to_ref -> user_info = "murali";
	addrspec_to_ref -> host_part = "172.16.5.148";
	addrspec_to_ref -> uri_param = NULL;
	/* toparams */
	TOPARAMS *toparams_ref = to_ref -> to_params;	
	toparams_ref -> tag = "34h3jkh2k34b3k234j34h4bk2lvvg23"; 
	
/* User agent */

	messageheader_ref -> user_agent = "SIP client";
	
/* Via */

	VIA *via_ref = messageheader_ref -> via;
	
	/* viaparam */
	VIAPARAM *viaparam_ref = via_ref -> via_param;

	/* sentprotocol */	
	SENTPROTOCOL *sentprotocol_ref = viaparam_ref -> sent_protocol;
	sentprotocol_ref -> protocol_name = "sfdfsdf";
	sentprotocol_ref -> protocol_version = "sdfsdf";
	sentprotocol_ref -> transport = "sdfsddfsdf";

	/* sentby */
	SENTBY *sentby_ref = viaparam_ref -> sent_by;
	sentby_ref -> host = "host";
	sentby_ref -> port = "port";

	/* viaparam */
	VIAPARAMS *viaparams_ref = viaparam_ref -> via_params;
	viaparams_ref -> ttl = "ttl";
	viaparams_ref -> branch = "branch";
	viaparams_ref -> maddr = "maddr";
	viaparams_ref -> received = "reveived";
	viaparams_ref -> rport = "rport";

/* Content type */
	messageheader_ref -> content_type = "application/SDP";
}
