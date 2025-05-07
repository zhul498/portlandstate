; rchaney@pdx.edu
; R Jesse Chaney

extern printf			; the C function, to be called
global main				; the standard gcc entry point

section .bss			; BSS, uninitialized identifiers

section .data			; Data section, initialized identifiers

section .rodata         ; Read-only section, immutable identifiers

section .text			; Code section.

main:					; the program label for the entry point
	; Don't change or remove the lines of code in here  |
	push ebp			; set up stack frame			|
	mov ebp, esp		;								|
	; Don't change or remove the lines of code in here	|


	; 
	; Your NASM code will go in here
	;















	; Don't change or remove the lines of code in here  |
	mov	esp, ebp		; takedown stack frame			|
	pop	ebp				;								|
						;								|
	mov	eax, 0			; no error return value			|
	ret					; return						|
	; Don't change or remove the lines of code in here  |
