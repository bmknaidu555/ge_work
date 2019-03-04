#include "header.h"

int init_packet(PACKET **packet)
{
	*packet = (PACKET *) alloc_memory (sizeof (PACKET));	
	return EXIT_SUCCESS;
}

int init_startline(PACKET *packet, int (*fun_ptr)(STRTLINE *startline_ref))
{
	STRTLINE *startline_ref = NULL;	
	startline_ref = (packet -> start_line = 
							(STRTLINE *) alloc_memory (sizeof (STRTLINE))); 
	fun_ptr(startline_ref);
	return EXIT_SUCCESS;}

/* start_line */
int request_line(STRTLINE *startline_ref)
{
	REQLINE	*reqline_ref = NULL;
	REQURI *requri_ref = NULL;
	SIPURI *sipuri_ref = NULL;

	reqline_ref  =  startline_ref -> req_line = 
					(REQLINE *) alloc_memory (sizeof (REQLINE));
	requri_ref = (reqline_ref -> request_uri = 
					(REQURI *) alloc_memory (sizeof (REQURI)));
	reqline_ref -> version = 
					(char *) alloc_memory (sizeof (SIP_VERSION_SIZE));	
	sipuri_ref = requri_ref -> sip_uri = 
					(SIPURI *) alloc_memory (sizeof (SIPURI));

	return EXIT_SUCCESS;
}

int response_line(STRTLINE *startline_ref)
{	
	RESLINE * resline_ref = NULL;

	resline_ref = startline_ref -> res_line = 
					(RESLINE *) alloc_memory (sizeof (RESLINE));
			
	return EXIT_SUCCESS;
}

/*			MESSAGE_HEADER
	 ============================
*/

int init_message_hddr(PACKET *packet, unsigned int count, ...)
{	
	va_list list;
	int (*caller)(MSGHDR *messageheader_ref);
	MSGHDR *messageheader_ref;	
	messageheader_ref = (MSGHDR *) alloc_memory (sizeof (MSGHDR));

	va_start(list, count);
	while(count-- != 0) {
		caller = va_arg(list, int(*)(MSGHDR *));
		caller(messageheader_ref);
	}
	va_end(list);

	return EXIT_SUCCESS;	 
}

int accept( MSGHDR *messageheader_ref)
{
	return EXIT_SUCCESS;
}

int call_id(MSGHDR *messageheader_ref)
{
	CALLID *callid_ref = NULL;
	callid_ref = messageheader_ref -> call_id =
					(CALLID *) alloc_memory (sizeof (CALLID));
	return EXIT_SUCCESS;
}

int contact(MSGHDR *messageheader_ref)
{
	CONTACT *contact_ref = NULL;
	CONTACTPARAM *contactparam_ref = NULL;
 	CONTACTPARAMS *contactparams_ref = NULL;
 	NAMEADDR *nameaddr_ref = NULL;
 	ADDRSPEC *addrspec_ref = NULL;
	
	contact_ref = messageheader_ref -> contact =
					(CONTACT *) alloc_memory (sizeof (CONTACT));  
	contactparam_ref = contact_ref -> cont_param = 
					(CONTACTPARAM *) alloc_memory (sizeof (CONTACTPARAM));
	nameaddr_ref = contactparam_ref -> name_addr =
					(NAMEADDR *) alloc_memory (sizeof (NAMEADDR));
	contactparams_ref = contactparam_ref -> cont_params = 
					(CONTACTPARAMS *) alloc_memory (sizeof (CONTACTPARAMS));
	addrspec_ref = nameaddr_ref -> addr_spec =
					(ADDRSPEC *) alloc_memory (sizeof (ADDRSPEC));
	return EXIT_SUCCESS;
}

int content_length(MSGHDR *messageheader_ref)
{

	return EXIT_SUCCESS;
}

int content_type(MSGHDR *messageheader_ref)
{

	return EXIT_SUCCESS;
}

int cseq(MSGHDR *messageheader_ref)
{
	CSEQ *cseq_ref = NULL;
	cseq_ref = messageheader_ref -> cseq = 
					(CSEQ*) alloc_memory (sizeof (CSEQ));
	cseq_ref -> cseq_no = "234";
	cseq_ref -> method_name = "Method name";
	return EXIT_SUCCESS;
}

int from(MSGHDR *messageheader_ref)
{
	FROM *from_ref = NULL;
 	FROMPARAMS *fromparams_ref = NULL;
	from_ref = messageheader_ref -> from = 
					(FROM *) alloc_memory (sizeof (FROM));
	fromparams_ref = from_ref -> from_params =
					(FROMPARAMS *) alloc_memory (sizeof (FROMPARAMS));	
	return EXIT_SUCCESS;
}

int max_forward(MSGHDR *messageheader_ref)
{
	return EXIT_SUCCESS;
}

int to(MSGHDR *messageheader_ref)
{
	TO *to_ref =  NULL;
	TOPARAMS *toparams_ref = NULL;
	
	to_ref = messageheader_ref -> to = 
							(TO *) alloc_memory (sizeof (TO));
	toparams_ref = to_ref -> to_params = 
							(TOPARAMS *) alloc_memory (sizeof (TOPARAMS));	
	return EXIT_SUCCESS;
}

int user_agent(MSGHDR *messageheader_ref)
{
	messageheader_ref -> user_agent = "SipClient v1.0";
	return EXIT_SUCCESS;
}

int via(MSGHDR *messageheader_ref)
{
	VIA *via_ref = NULL;
	VIAPARAM *viaparam_ref = NULL;
	SENTPROTOCOL *sentprotocol_ref = NULL;
 	SENTBY *sentby_ref = NULL;
 	VIAPARAMS *viaparams_ref = NULL;

	via_ref = messageheader_ref -> via = 
					(VIA *) alloc_memory (sizeof (VIA));
		
	viaparam_ref = via_ref -> via_param = 
					(VIAPARAM *) alloc_memory (sizeof (VIAPARAM));
	sentprotocol_ref = viaparam_ref -> sent_protocol = 
					(SENTPROTOCOL *) alloc_memory (sizeof (SENTPROTOCOL)); 

	/*sentprotocol_ref -> protocol_name;	
	sentprotocol_ref -> protocol_version;
	sentprotocol_ref -> transport;*/

	sentby_ref = viaparam_ref -> sent_by =
					(SENTBY *) alloc_memory (sizeof (SENTBY));
		
	/*sentby_ref -> host;
	sentby_ref -> port;*/ 
	viaparams_ref = viaparam_ref -> via_params = 
					(VIAPARAMS *) alloc_memory (sizeof (VIAPARAMS));
	return EXIT_SUCCESS;
}

