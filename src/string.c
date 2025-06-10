#include "string.h"
#include <stddef.h>
#include <stdint.h>

void *
memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		*(uint8_t *) (dest + i) = *(uint8_t *) (src + i);
		++i;
	}

	return dest;
}

/*void *memmove(void *dest, const void *src, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		__asm__ __volatile__ (
			"push %%ax;" : : "a"(*(uint8_t *) (src + i))
		);
		++i;
	}

	while (0 < i)
	{
		--i;
		__asm__ __volatile__ (
			"pop %%ax;" : "=a"(*(uint8_t *) (dest + i))
		);
	}

	return dest;
}*/

void *
memset(void *s, int c, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		*(uint8_t *) (s + i) = c;
		++i;
	}

	return s;
}

int
memcmp(const void *s1, const void *s2, size_t n)
{
	int	res;
	size_t i = 0;

	while (i < n)
	{
		res = *(uint8_t *) (s1 + i) - *(uint8_t *) (s2 + i);
		
		if (res)
			return res;
		
		++i;
	}

	return res;
}
