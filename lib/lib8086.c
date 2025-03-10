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

void *memmove(void *dest, const void *src, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		__asm__ __volatile__ (
			"push %%ax" : : "a"(*(char *) (src + i))
		);
		++i;
	}

	while (0 < i)
	{
		--i;
		__asm__ __volatile__ (
			"pop %%ax" : "=a"(*(char *) (dest + i))
		);
	}

	return dest;
}

void *memset(void *s, int c, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		*(char *) (s + i) = c;
		++i;
	}

	return s;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
	int	res;
	size_t i = 0;

	while (i < n)
	{
		res = *(byte *) (s1 + i) - *(byte *) (s2 + i);
		
		if (res)
			return res;
		
		++i;
	}

	return res;
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
		"int $0x10;" : : "a"(0x0e00 | c), "b"(0x0007)
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
