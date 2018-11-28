; %1 string to print
%macro print 1
  sub  esp, 16
  mov  dword [esp], %1
  call _printf
  add  esp, 16
%endmacro

; %1 fmt string
; %2 data [immediate]
%macro printData 2
  sub  esp, 16
  mov  dword [esp], %1
  mov  dword [esp+4], %2
  call _printf
  add  esp, 16
%endmacro
