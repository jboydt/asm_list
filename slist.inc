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
  makeNode %1
  mov ebx, [%2] ; ebx is head pointer/temp
  cmp ebx, 0
  jne %%_start_pushtail_loop
  pushHead %1, %2
  jmp %%_end
  %%_start_pushtail_loop:
    cmp dword[ebx + Node.next], 0
    je  %%_tail_found
    mov ebx, [ebx + Node.next]
    jmp %%_start_pushtail_loop
  %%_tail_found:
    ; ebx points to eax (new node)
    mov [ebx + Node.next], eax
    ; eax points to null (tail)
  mov dword[eax + Node.next], 0
  %%_end:
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
   cmp dword[eax + Node.next], 0
   je  %%_is_Tail
   mov eax, [eax + Node.next]
   jmp %%_start_PrintL

 %%_is_Tail:
   print promptEnd
   print endline
   %%_end:
%endmacro

; %1 head pointer [memory]
%macro popHead 1
pushad
  cmp dword[%1], 0
  jne %%_startPop
  print emptyls
  jmp %%_end
  ; Track the node to be removed
  %%_startPop:
  mov ebx, [%1]
  ; Move head to next node over
  mov eax, [ebx + Node.next]
  mov [%1], eax
  ; remove the old head node
  freeNode ebx
  %%_end:
popad
%endmacro

; %1 head pointer [memory]
%macro popTail 1
pushad
  ; Find the last node and next to last node
  mov edx, 0
  mov ebx, [%1]
  cmp ebx, 0
  je  %%_empty
  %%_startloop:
  mov ecx, [ebx + Node.next]
  cmp ecx, 0
  je  %%_removal
  mov edx, ebx
  mov ebx, ecx
  jmp %%_startloop
  ; Track the node to be removed
  ; remove the old head node
  %%_notHead:
  cmp edx, 0
  je  %%_end
  mov dword[edx + Node.next], 0
  jmp %%_end
  %%_empty:
  print emptyls
  jmp %%_end
  %%_removal:
  freeNode ebx
  cmp ebx, [%1]
  jne %%_notHead
  mov dword[%1], 0
  ; null next to last node's pointer
  %%_end:
popad
%endmacro

; %1 head pointer [memory]
%macro clearList 1
  pushad
    cmp dword [%1], 0
    je %%_end

  %%_start_delete:
      mov ebx, [%1]
      mov eax, [ebx + Node.next]
      freeNode ebx
      mov [%1], eax
      mov ebx, eax

      cmp ebx, 0
      jne %%_start_delete
      jmp %%_end_loop

    %%_end:
      print emptyls

    
  %%_end_loop:
  print emptyls
  popad
%endmacro

; This macro will insert a node in sorted ascending order
; %1 value to insert
; %2 head pointer
%macro insertNode 2
  pushad

  makeNode %1                                    ; Allocate memory for node

  mov  ebx, [%2]                                 ; ebx (upper counter) starts at head pointer
  mov  ecx, [%1]                                 ; ecx will hold the value to insert
  cmp  ebx, 0                                    ; Check if list is empty
  je   %%_insert_at_head                         ; If list is empty, insert at head
  cmp  ecx, [ebx + Node.data]                    ; Check if value is greater than head
  jg   %%_insert_next                            ; If value is greater, check next value
  jmp  %%_insert_at_head

  %%_insert_at_head:
    mov  dword [eax + Node.next], ebx            ; Move upper counter to next node
    mov  [head], eax                             ; Place created node at head
    jmp  %%_end

  %%_insert_next:
    mov  edx, ebx                                ; edx (lower counter)
    mov  ebx, [ebx + Node.next]                  ; Point ebx to next element
    cmp  ebx, 0
    je   %%_insert_here                          ; If upper counter points to empty node, insert here
    mov  ecx, [%1]
    cmp  [ebx + Node.data], ecx
    jg   %%_insert_here                          ; If value to insert is lower than current node, insert here
    jmp  %%_insert_next                          ; Loop

  %%_insert_here:
    mov  [edx + Node.next], eax                  ; Point previous node to new node
    mov  [eax + Node.next], ebx                  ; Point new node to next node
    jmp  %%_end

  %%_end:

  popad
%endmacro

; %1 node to be removed [immediate]
%macro freeNode 1
  pushad

  sub esp, 16
  mov dword [esp], %1
  call _free
  add esp, 16

  popad
%endmacro

; %1 value to insert [memory]
%macro makeNode 1
  sub  esp, 16
  mov  dword [esp], Node.size
  call _malloc
  mov  ebx, [%1]
  mov  dword [eax + Node.data], ebx
  mov  dword [eax + Node.next], 0
  add  esp, 16
%endmacro

; %1 fmt string
; %2 node address [memory]
%macro printNode 2
  mov  eax, [%2 + Node.data]
  printData %1, eax
%endmacro
