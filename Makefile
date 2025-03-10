CC = ia16-elf-gcc
LD = ia16-elf-ld
OC = ia16-elf-objcopy

CCFLAGS = -Os -ffreestanding -Wall -Werror -Ilib
LDFLAGS = -static -Tlink.ld -nostdlib --nmagic -Llib
OCFLAGS = -O binary

all: main.bin qemu

main.bin: main.elf
	$(OC) $(OCFLAGS) $< $@

main.elf: main.o lib8086.o
	$(LD) $(LDFLAGS) $^ -o $@

main.o: src/main.c lib/lib8086.h
	$(CC) $(CCFLAGS) -c $< -o $@

lib8086.o: lib/lib8086.c lib/lib8086.h
	$(CC) $(CCFLAGS) -c $< -o $@

qemu:
	qemu-system-x86_64 -drive format=raw,file=main.bin

dump:
	$(CC) $(CCFLAGS) -S src/main.c -o dump.S
	hexdump -C main.bin

clean:
	rm -f dump.S *.o *.elf *.bin

archive:
	git archive -o ar/8086_$(shell date "+%Y%m%d").tar.gz main
