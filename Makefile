# uncomment for Linux
#CC = gcc
#CO = gcc -m32
#FORMAT = elf32
#RM = rm -f

# uncomment for Mac OS X
#CC = gcc
#CO = ld -lc -macosx_version_min 10.13
#FORMAT = macho32
#CL = -dMAC=1
#RM = rm -f

# uncomment for Windows (make sure MinGW/MSYS are installed!)
<<<<<<< HEAD
 CC = c:\mingw\bin\gcc
 CO = $(CC)
 FORMAT = win32
 CL = -dWINDOWS=1
 #RM = del # cmd.exe
RM = rm -fo # PowerShell
=======
 CC = gcc
 CO = $(CC)
 FORMAT = win32
 CL = -dWINDOWS=1
 RM = del # cmd.exe
#RM = rm -fo # PowerShell
>>>>>>> bf2651ad985cd088ae82550e099d89faeb34d370

project4.exe: project4.obj
	$(CO) project4.obj -o project4.exe

project4.obj: project4.asm
	nasm $(CL) -f $(FORMAT) project4.asm -o project4.obj

clean:
	$(RM) *.obj

cleanall: clean
	$(RM) *.exe *.obj
