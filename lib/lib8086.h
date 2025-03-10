#ifndef __LIB8086_H__
#define __LIB8086_H__

typedef unsigned int size_t;

void *memcpy(void *dest, const void *src, size_t n);
void setVideoMode(int mode);
void putc(char c);
void puts(const char *s);
int getc(void);
char *gets(char *s);

#endif/*__LIB8086_H__*/
