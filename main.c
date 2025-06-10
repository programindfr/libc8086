#include "8086.h"
#include "stdio.h"

void main(void)
{
	char buff[32];

	setVideoMode(0x12);
	puts("Quel est ton prenom ?\r\n");
	gets(buff);

	puts("Bonjour ");
	puts(buff);
	puts(" !");
}
