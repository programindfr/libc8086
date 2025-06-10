#include "stdio.h"
#include <stddef.h>

void
putc(char c)
{
	__asm__ __volatile__ (
		"int $0x10;" : : "a"(0x0e00 | c), "b"(0x0007)
	);
}

void
puts(const char *s)
{
	while (*s)
	{
		putc(*s);
		++s;
	}
}

int
getc(void)
{
	int c;

	__asm__ __volatile__ (
		"int $0x16;" : "=a"(c) : "a"(0x0000)
	);

	return 0x00ff & c;
}

char *
gets(char *s)
{
	char   c = '\0';
	size_t i = 0;

	while (c != '\r')
	{
		c = getc();
		s[i] = c;
		putc(c);
		++i;
	}

	s[i - 1] = '\0';
	putc('\n');
	
	return s;
}
