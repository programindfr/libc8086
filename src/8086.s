.code16
.global setVideoMode
.global write
.global read

.text
setVideoMode:
	# arg0: sp + 2 -> size_t mode
	# ret:  ax -> 0
	mov %sp, %bx
	mov 2(%bx), %ax
	int $0x10
	ret

write:
	# arg0: sp + 2 -> char c
	# ret:  ax -> 0
	mov %sp, %bx
	mov 2(%bx), %al
	mov $0x0e, %ah
	mov $0x0007, %bx
	int $0x10
	ret

read:
	# ret: ax -> size_t
	xor %ax, %ax
	int $0x16
	xor %ah, %ah
	ret
