#include <lib8086.h>

void main(void)
{
	char c[] = "How are you ?\r\n";
	char buff[32];

	setVideoMode(0x12);
	puts("Hello World !\r\n");
	puts(c);
	
	gets(buff);
	puts(buff);
	puts("\r\nhey!");
}
