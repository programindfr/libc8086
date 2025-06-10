#include "8086.h"

void
setVideoMode(int mode)
{
	__asm__ __volatile__ (
		"int $0x10;" : : "a"(mode)
	);
}
