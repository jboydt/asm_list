; Project 4
; project4.asm

[bits 32]

global _main

extern _printf
extern _scanf
extern _system
extern _malloc

%include "util.inc"
%include "slist.inc"

section .data
	endline		db 	"", 10, 0
	welcome		db 	"Welcome to the linked list program!", 10, 10, 0
	prompt1		db 	"1. Push head", 10, 0
	prompt2		db 	"2. Pop head", 10, 0
	prompt3		db 	"3. Push tail", 10, 0
	prompt4		db 	"4. Pop tail", 10, 0
	prompt5		db 	"5. Clear list", 10, 0
	prompt0		db 	"0. Exit", 10, 0
	enterpm		db 	"your choice:  ", 0
	goodBye		db	"Shutting Down...", 0
	datapmt		db	"Please enter a number", 0
	insrtVal	db	0
	usrchoice	db 	0
	loppmt		db 	"Would you like to play again.", 10, 0
	datafmt		db 	"%i ", 0
	charfmt		db 	" %u"
	invalid		db 	"Invalid entry", 10, 0

	head		dd 	0
	tail		dd	0

section .bss

section .text
_main:
	push  ebp
	mov   ebp, esp
	and   esp, 0xfffffff0

	print welcome
	_start:
	 print	prompt1
	 print	prompt2
	 print	prompt3
	 print	prompt4
	 print	prompt5
	 print	prompt0
	 print	enterpm
	 scan 	usrchoice, datafmt
	 mov 	ebx, dword[usrchoice]
	 cmp 	ebx, 1
	 je 	_pushHead
	 cmp 	ebx, 2
	 je 	_popHead
	 cmp 	ebx, 3
	 je 	_pushTail
	 cmp 	ebx, 4
	 je 	_popTail
	 cmp 	ebx, 5
	 je 	_clearList
	 cmp 	ebx, 0
	 je 	_exit
	 cls
	 print 	invalid
	 jmp	_start

	_pushHead:
	cls
	print	datapmt
	scan 	insrtVal, datafmt
	jmp _start

	_popHead:
	cls
	print	datapmt
	scan 	insrtVal, datafmt
	jmp _start

	_pushTail:
	cls
	print	datapmt
	scan 	insrtVal, datafmt
	jmp _start

	_popTail:
	cls
	print	datapmt
	scan 	insrtVal, datafmt
	jmp _start

	_clearList:
	cls
	print	datapmt
	scan 	insrtVal, datafmt
	jmp _start
	
	_exit:
	cls
	print goodBye
	mov  	esp, ebp
	mov   	eax, 1
	pop   	ebp
ret
