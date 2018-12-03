struc Node
  .data: resd 1
  .next: resd 1
  .size:
endstruc

%macro pushHead 2
  makeNode %1
  ; memory to memory needs to be resolved 
  ; mov [eax + Node.next], [%2] ; links new node to current head node
  mov ebx, [%2]
  mov [eax + Node.next], [ebx]
  mov [%2], eax
%endmacro

; %1 number of bytes to allocate [immediate]
; %2 pointer variable [memory]
%macro makeNode 2
  sub  esp, 16
  mov  dword [esp], %1
  call _malloc
  mov  ebx, [%1]
  mov  dword [%2 + Node.data], ebx
  mov  dword [%2 + Node.next] , 0
  add  esp, 16
%endmacro

; %1 fmt string
; %2 node address [memory]
%macro printNode 2
  mov  eax, [%2 + Node.data]
  printData %1, eax
%endmacro
