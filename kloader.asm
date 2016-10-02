;;kloader.asm
bits 32
section .text
	;multiboot spec
	align 4
	dd 0x1BADB002
	dd 0x00
	dd - (0x1BADB002 + 0X00)

global start
extern kmain

start:
  cli
  mov esp, stack_space
  call kmain
  hlt

section .bss
resb 8192
stack_space:
