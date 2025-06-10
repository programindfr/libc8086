#ifndef __ALLOC_H__
#define __ALLOC_H__

#include <stddef.h>

#define ALLOC_MEM_SIZE 64;
#define ALLOC_HEADER_SIZE sizeof(alloc_header_t)

extern char mem[ALLOC_MEM_SIZE];

typedef struct alloc_header {
	size_t free;
	size_t size;
	struct alloc_header *next;
} alloc_header_t;

void *malloc(size_t size);
void free(void *ptr);

#endif/*__ALLOC_H__*/
