#include<stdio.h>
struct ip
{
	unsigned char version:4;
	unsigned char header_length:4; 
	unsigned short service_type:8;
	unsigned short total_length;

	unsigned short identification;
	unsigned short flags:4;
	unsigned short:12;

	unsigned short TTL : 7;
	unsigned short Protocol : 9;
	unsigned short header_checksum;

	unsigned int source;

	unsigned int destination;
	
	unsigned int options : 20;	

	
}packet;


int main()
{
	printf("Size of structure is %d", sizeof(packet)); 
}
