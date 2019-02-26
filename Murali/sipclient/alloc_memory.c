#include "header.h"

void* alloc_memory(size_t size)
{
	void *pointer = NULL;
	pointer = malloc(size);
	if(pointer == NULL) {
		dumplog("Unable to allocate memory", __func__, __FILE__, __LINE__);
		exit(EXIT_FAILURE);
	} else
		return pointer;
}
