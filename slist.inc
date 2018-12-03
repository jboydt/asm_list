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
  ; Starting at head node, do
  ; loop
  ; print currentNode.data, fmt string
  ; walk/iterate to next node
  ; loop
%endmacro

; %1 head pointer [memory]
%macro popHead 1
pushad
  ; Track the node to be removed
  mov ebx, %1
  ; Move head to next node over
  mov %1, [ebx + Node.next]
  ; remove the old head node
  freeNode ebx
popad
%endmacro

; %1 head pointer [memory]
%macro popTail 1
  ; Find the last node and next to last node
  ; Track the node to be removed
  ; remove the old head node
  ; null next to last node's pointer
%endmacro

; %1 head pointer [memory]
%macro clearList 1
  ; Loop and free all nodes
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
