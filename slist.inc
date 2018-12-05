struc Node
  .data: resd 1
  .next: resd 1
  .size:
endstruc

; %1 value to insert [memory]
; %2 head pointer [memory]
%macro pushHead 2
  makeNode %1
  mov ebx, [%2]
  mov [eax + Node.next], ebx
  mov [%2], eax
%endmacro

; %1 value to insert [memory]
; %2 head pointer [memory]
%macro pushTail 2
  ; 1. Make a new node with %1 (data)
  ; 2. Find the last node
  ; 3. Do lastNode.next = newNode
%endmacro

; %1 head pointer [memory]
; %2 fmt string
%macro printList 2
    ;Starting at head node, do
   cmp dword[%1], 0
   je %%_end
  mov eax, [%1]
  %%_start_PrintL:

   mprint %2, dword eax + Node.data
   print endline
   cmp dword[eax + Node.next], 0
   je  %%_is_Tail
   mov eax, [eax + Node.next]
   jmp %%_start_PrintL

 %%_is_Tail:
   print promptEnd
   %%_end:
%endmacro

; %1 head pointer [memory]
%macro popHead 1
  ; Track the node to be removed
  ; Move head to next node over
  ; remove the old head node
%endmacro

; %1 head pointer [memory]
%macro popTail 1
  ; Find the last node and next to last node
  ; Track the node to be removed
  ; remove the old head node
  ; null next to last node's pointer
%endmacro

; %1 head pointer [memory]
pushad
%macro clearList 1

    cmp [%1], 0
    je %%_end_loop

  %%_start_delete:
      mov ebx, [%1]
      mov eax, [%1 + Node.next]
      freeNode ebx
      mov [%1], eax
      mov ebx, eax

      cmp ebx, 0
      jne %%_start_delete

  %%_end_loop:
    ; do nothing
popad
%endmacro

; %1 node to be removed [immediate]
%macro freeNode 1
  sub esp, 16
  mov dword [esp], %1
  call _free
  add esp, 16
%endmacro

; %1 value to insert [memory]
%macro makeNode 1
  sub  esp, 16
  mov  dword [esp], Node.size
  call _malloc
  mov  ebx, [%1]
  mov  dword [eax + Node.data], ebx
  mov  dword [eax + Node.next] , 0
  add  esp, 16
%endmacro

; %1 fmt string
; %2 node address [memory]
%macro printNode 2
  mov  eax, [%2 + Node.data]
  printData %1, eax
%endmacro
