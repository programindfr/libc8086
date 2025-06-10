CC = ia16-elf-gcc
LD = ia16-elf-ld
OC = ia16-elf-objcopy

CCFLAGS = -Os -ffreestanding -ffunction-sections -Wall -Wextra -Werror -Isrc/include
LDFLAGS = -static -Tlink.ld -nostdlib --nmagic -Lsrc/include
OCFLAGS = -O binary

all: main.bin qemu

main.bin: main.elf
	$(OC) $(OCFLAGS) $< $@

main.elf: main.o 8086.o stdio.o
	$(LD) $(LDFLAGS) $^ -o $@

main.o: main.c src/include/8086.h src/include/stdio.h
	$(CC) $(CCFLAGS) -c $< -o $@

8086.o: src/8086.c src/include/8086.h
	$(CC) $(CCFLAGS) -c $< -o $@

stdio.o: src/stdio.c src/include/stdio.h
	$(CC) $(CCFLAGS) -c $< -o $@

qemu:
	qemu-system-x86_64 -drive format=raw,file=main.bin

dump:
	ia16-elf-objdump -D -M i8086 -M att main.elf
	hexdump -C main.bin

clean:
	rm -f *.o *.elf *.bin

archive:
	git archive -o 8086_$(shell date "+%Y%m%d").tar.gz main
