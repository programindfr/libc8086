#ifndef __LIB8086_H__
#define __LIB8086_H__

typedef unsigned int size_t;
typedef unsigned char byte;

void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
void setVideoMode(int mode);
void putc(char c);
void puts(const char *s);
int getc(void);
char *gets(char *s);

#endif/*__LIB8086_H__*/
