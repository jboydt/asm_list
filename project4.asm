; Project 4
; project4.asm

[bits 32]

global _main

extern _printf
extern _malloc

%include "util.inc"
%include "slist.inc"

section .data
	endline    	db "", 10, 0
	welcome   	db "Welcome to the linked list program!", 10, 10, 0
	prompt1		db "1. Push head", 10, 0
	prompt2		db "2. Pop head", 10, 0
	prompt3		db "3. Push tail", 10, 0
	prompt4		db "4. Pop tail", 10, 0
	prompt5		db "5. Clear list", 10, 0
	prompt0		db "0. Exit", 10, 0
	enterpm		db "your choice:  ", 0
	usrchoice	db 0
	loppmt		db "Would you like to play again.", 10, 0
	datafmt    	db "%i ", 0
	charfmt		db "%u"
	invalid		db "Invalid entry", 10, 0
	

	head       	dd 0

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
	 mov 	eax, dword[usrchoice]
	 cmp 	eax, 1
	 je 	_pushHead
	 cmp 	eax, 2
	 je 	_popHead
	 cmp 	eax, 3
	 je 	_pushTail
	 cmp 	eax, 4
	 je 	_popTail
	 cmp 	eax, 5
	 je 	_clearList
	 cmp 	eax, 0
	 je 	_exit
	 cls
	 print 	invalid
	 jmp	_start
	 
	_pushHead:
	_popHead:
	_pushTail:
	_popTail:
	_clearList:
	_exit:
	
	_ask_restart:
	 print	loppmt

	 sub	esp, 16
	 mov	dword [esp], charfmt
	 mov	dword [esp+4], input
	 call	_scanf
	 add	esp, 16

	 mov	al, [input]
	 cmp 	al, 96
	 jna 	_check_restart
	 sub 	al, 32

	_check_restart:
	  cmp	al, 89
	  je	_start
	mov  	esp, ebp
	mov   	eax, 1
	pop   	ebp
ret
