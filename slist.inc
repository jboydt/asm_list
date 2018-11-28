struc Node
  .data: resd 1
  .next: resd 1
  .size:
endstruc

; %1 number of bytes to allocate [immediate]
; %2 pointer variable [memory]
%macro makeNode 2
  sub  esp, 16
  mov  dword [esp], %1
  call _malloc
  mov  dword [%2], eax
  mov  dword [%2 + Node.data], 0
  mov  dword [%2 + Node.next] , 0
  add  esp, 16
%endmacro

; %1 fmt string
; %2 node address [memory]
%macro printNode 2
  mov  eax, [%2 + Node.data]
  printData %1, eax
%endmacro
