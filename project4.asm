; Project 4
; project4.asm

[bits 32]

global _main

extern _printf
extern _malloc

%include "util.inc"
%include "slist.inc"

section .data
  endline    db "", 10, 0
  welcome    db "Welcome to the linked list program!", 10, 10, 0

  datafmt    db "%i ", 0

  head       dd 0

section .bss

section .text
_main:
  push  ebp
  mov   ebp, esp
  and   esp, 0xfffffff0

  print welcome

  makeNode Node.size, head
  printNode datafmt, head

  mov   esp, ebp
  mov   eax, 1
  pop   ebp
ret
