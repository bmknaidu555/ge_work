#include "header.h"


void fill_start_line(PACKET *packet, 
				const char *method_name, const char *host, const char *sip_version)
{
	STRTLINE *startline_ref = NULL;
	REQLINE *reqline_ref = NULL;
	REQURI *requri_ref = NULL;
	SIPURI *sipuri_ref = NULL;

	startline_ref = packet -> start_line;
    reqline_ref  = startline_ref -> req_line;
    requri_ref = reqline_ref -> request_uri;
    sipuri_ref = requri_ref -> sip_uri;
  
    reqline_ref -> method_name = method_name;
    /* Registrar domain */
    sipuri_ref -> host_port = host;
    reqline_ref -> version = sip_version;
}


void fill_callid(PACKET *packet, const char *callid, const char *host)
{
	MSGHDR *messageheader_ref = NULL;
	messageheader_ref = packet -> msg_hddr;

	/* Callid */
	CALLID *callid_ref = messageheader_ref -> call_id;
	callid_ref -> callid = callid;
	callid_ref -> host = host;
}

void fill_contact(PACKET *packet, const char *display_name, const char *user_info
									const char *host_part, const char *uri_param )
{
	MSGHDR *messageheader_ref = NULL;
	messageheader_ref = packet -> msg_hddr;

 	CONTACT *contact_ref = messageheader_ref -> contact;
 	/* contactparam */ 
 	CONTACTPARAM *contactparam_ref = contact_ref -> cont_param;
 	/*  ->  nameaddr */
 	NAMEADDR *nameaddr_contact_ref = contactparam_ref -> name_addr;
 	nameaddr_contact_ref -> display_name = "murali krishna";
 	/*      -> addrspec */
 	ADDRSPEC *addrspec_contact_ref = nameaddr_contact_ref -> addr_sp    ec; 
	addrspec_contact_ref -> user_info = "murali";								
	addrspec_contact_ref -> host_part = "172.16.5.148";
	addrspec_contact_ref -> uri_param = ;
}

