; %1 string to print
%macro print 1
  pushad
  sub  esp, 16
  mov  dword [esp], %1
  call _printf
  add  esp, 16
  popad
%endmacro

; %1 fmt string
; %2 data [immediate]
%macro printData 2
  pushad
  sub  esp, 16
  mov  dword [esp], %1
  mov  dword [esp+4], %2
  call _printf
  add  esp, 16
  popad
%endmacro

; Gary's macs
; %1 string
; %2 fmt
%macro mprint 2
	pushad
	sub		esp, 16
  mov		dword[esp], %1
	mov		eax, [%2]
	mov		dword[esp+4], eax
  call	_printf
  add		esp, 16
	popad
%endmacro
%macro	cls 0
  pushad
	sub		esp, 16
	mov		dword[esp], "CLS"
	call	_system
	add		esp, 16
  popad
%endmacro
;%1 input location
;%2 fmt
%macro scan 2
	pushad
	sub		esp, 16
    mov		dword[esp], %2
    mov		dword[esp+4], %1
    call	_scanf
    add		esp, 16
	popad
%endmacro
