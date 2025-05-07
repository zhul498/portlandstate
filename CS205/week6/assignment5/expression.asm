; rchaney@pdx.edu
; R Jesse Chaney

extern printf			; the C function, to be called
extern scanf			; We will be calling scanf()

global main			; the standard gcc entry point

section .bss			; BSS, uninitialized identifiers
	y: resd 1

section .data			; Data section, initialized identifiers
	m: dd 0
	x: dd 0
	b: dd 0

section .rodata         ; Read-only section, immutable identifiers
	fmt_show_expression: db "You will calculate the expression y = mx + b", 10, 0
	fmt_show_result: db "Your expression %d = %d * %d + %d", 10, 0
	fmt_get_m: db 9, "Enter the value for m: ", 0
	fmt_get_x: db 9, "Enter the value for x: ", 0
	fmt_get_b: db 9, "Enter the value for b: ", 0
	fm_get_value: db "%d", 0

section .text			; Code section.

main:					; the program label for the entry point
	; Don't change or remove the lines of code in here   |
	push ebp			; set up stack frame |
	mov ebp, esp		;			     |
	; Don't change or remove the lines of code in here   |


	; 
	; Your NASM code will go in here
	;

	push fmt_show_expression
	call printf
	add esp, 4

	push fmt_get_m
	call printf
	add esp, 4

	push m
	push fmt_get_value
	call scanf
	add esp, 8

	push fmt_get_x
	call printf
	add esp, 4

	push x
	push fmt_get_value
	call scanf
	add esp, 8

	push fmt_get_b
	call printf
	add esp, 4

	push b
	push fmt_get_value
	call scanf
	add esp, 8

	mov eax, [ m ]
	imul eax, [ x ] 
	add eax, [ b ]
	mov [ y ], eax

	push dword [ b ]
	push dword [ x ] 
	push dword [ m ] 
	push dword [ y ]
	push fmt_show_result
	call printf
	add esp, 20


	; Don't change or remove the lines of code in here  	|
	mov	esp, ebp		; takedown stack frame	|
	pop	ebp				;		|
						;		|
	mov	eax, 0			; no error return value	|
	ret					; return	|
	; Don't change or remove the lines of code in here  	|
