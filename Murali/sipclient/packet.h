/* Packet structure */

typedef struct packet_struct {
	union startline_union *start_line;
	struct messageheader_struct *msg_hddr;
	struct messagebody_struct *msg_body;
} PACKET;
	
/* structure for startline */

typedef union startline_union {
	struct requestline_struct *req_line;
	struct responseline_struct *res_line;
} STRTLINE;

/* structure for request_line */

typedef struct requestline_struct {
	char *method_name;
	union requesturi_union *request_uri;
	char *version;
} REQLINE;

/* structure for response line */

typedef struct responseline_struct {
	char *version;
	char *status_code;
	char *response_phrase;	
} RESLINE;

/* Union for request URI */

typedef union requesturi_union {
	struct sipuri_struct *sip_uri;
	struct sipsuri_struct *sips_uri;
} REQURI;
/* Structure to maintain SipURI */

typedef struct sipuri_struct {
	char *user_info;
	char *host_port;	//ex : 117.26.4.32:7656 or domain
	//char *uri_param;
} SIPURI;

/* Structure to maintain sips URI */
typedef struct sipsuri_struct {

}SIPSURI;

/**************************************************************************/

/* structure for message header */

typedef struct messageheader_struct {
	struct callid_struct *call_id;
	struct contact_struct *contact;
	char *content_length;
	struct cseq_struct *cseq;
	struct from_struct *from;
	char *max_forwards;
	struct to_struct *to;
	char *user_agent;
	struct via_struct *via;
	char *content_type;
}MSGHDR;

/* Structure to maintain the callID */

typedef struct callid_struct {
	char *callid;
	char *host;
}CALLID;

/* Structure to maintain the contact */

typedef struct contact_struct {
	struct contactparam_struct *cont_param;
} CONTACT;

typedef struct contactparam_struct {
	struct nameaddr_struct *name_addr;
	struct contactparams_struct *cont_params;
	//struct contactparams_struct *next;
} CONTACTPARAM;

typedef struct nameaddr_struct {
	char *display_name;
	struct addrspec_struct *addr_spec;
} NAMEADDR;

typedef struct addrspec_struct {
	char *user_info;
	char *host_part;
	char *uri_param;
} ADDRSPEC;

typedef struct contactparams_struct {
	char *expires;
}CONTACTPARAMS;

/*    Cseq */

typedef struct cseq_struct {
	char *cseq_no;
	char *method_name;
}CSEQ;

/* From */

typedef struct from_struct {
	struct nameaddr_struct *name_addr;
	struct fromparams_struct *from_params;
}FROM;

typedef struct fromparams_struct {
	char *tag;
}FROMPARAMS;

/* To */

typedef struct to_struct {
	struct nameaddr_struct *name_addr;
	struct toparams_struct *to_params;
}TO;

typedef struct toparams_struct {
	char *tag;
}TOPARAMS;


/* Via */

typedef struct via_struct {
	struct viaparam_struct *via_param;
}VIA;

typedef struct viaparam_struct {
	struct sentprotocol_struct *sent_protocol;
	struct sentby_struct *sent_by;
	struct viaparams_struct *via_params;
}VIAPARAM;

typedef struct sentprotocol_struct {
	char *protocol_name;
	char *protocol_version;
	char *transport;
}SENTPROTOCOL;

typedef struct sentby_struct {
	char *host;
	char *port;
}SENTBY;

typedef struct viaparams_struct {
	char *ttl;
	char *branch;
	char *maddr;
	char *received;
	char *rport;
}VIAPARAMS;

/* Message body */

/************************************************************************/
