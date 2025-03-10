#include <lib8086.h>

void *memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		*(char *) (dest + i) = *(char *) (src + i);
		++i;
	}

	return dest;
}

void setVideoMode(int mode)
{
	__asm__ __volatile__ (
		"int $0x10;" : : "a"(mode)
	);
}

void putc(char c)
{
	__asm__ __volatile__ (
		"int $0x10;" : : "a"(0x0e00 | c), "b"(0x0002)
	);
}

void puts(const char *s)
{
	while (*s)
	{
		putc(*s);
		++s;
	}
}

int getc(void)
{
	int c;

	__asm__ __volatile__ (
		"int $0x16;" : "=a"(c) : "a"(0x0000)
	);

	return 0x00ff & c;
}

char *gets(char *s)
{
	char	c = '\0';
	size_t  i = 0;

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
