#include "alloc.h"
#include <stddef.h>

char mem[ALLOC_MEM_SIZE];

void *
malloc(size_t size)
{
	alloc_header_t *curr = NULL;
	alloc_header_t *next = NULL;

	curr = (alloc_header_t *) mem;
	
	if (!curr->size)
	{
		curr->free = 1;
		curr->size = ALLOC_MEM_SIZE - ALLOC_HEADER_SIZE;
		curr->next = NULL;
	}

	while (curr)
	{
		if (curr->free && curr->size >= size)
		{
			next = (alloc_header_t *) (curr + ALLOC_HEADER_SIZE + size);
			
			next->free = 1;
			next->size = curr->size - ALLOC_HEADER_SIZE - size;
			next->next = curr->next;
			
			curr->free = 0;
			curr->size = size;
			curr->next = next;

			return curr + ALLOC_HEADER_SIZE;
		}

		curr = curr->next;
	}

	return NULL;
}

void
free(void *ptr)
{

}
