#include <stdio.h>

int bit_swap (int value, int source, int destination)
{

return (value & ( ~ (1 << source) ^ (1 << destination))) ^ 
						( (((value >> source) & 1) << destination) ^ (((value >> destination) & 1) << source));
	
} 

