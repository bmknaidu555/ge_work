#include<stdio.h>

struct frame
{
	unsigned short source_port;
	unsigned short destination_port;
	unsigned int sequence_number;
	unsigned int Ack_number;
	
	unsigned short header_len:4;
	unsigned short reserved:6;
	unsigned short code_bits:6;
	unsigned short window;
	
	unsigned short checksum;
	unsigned short urgent;
	
	
}packet;


int main()
{
	printf("%d", sizeof(packet));
} 
