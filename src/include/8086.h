#ifndef __8086_H__
#define __8086_H__

#include <stddef.h>

#define VGA 0x12

extern void setVideoMode(size_t mode);
extern void write(char c);
extern size_t read(void);

#endif/*__8086_H__*/
