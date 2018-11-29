# uncomment for Linux
#CC = gcc
#CO = gcc -m32
#FORMAT = elf32
#RM = rm -f

# uncomment for Mac OS X
#CC = gcc
#CO = ld -lc -macosx_version_min 10.13
#FORMAT = macho32
#RM = rm -f

# uncomment for Windows (make sure MinGW/MSYS are installed!)
CC = c:\mingw\bin\gcc
CO = $(CC)
FORMAT = win32
RM = del # cmd.exe
#RM = rm -fo # PowerShell

project4.exe: project4.obj
	$(CO) project4.obj -o project4.exe

project4.obj: project4.asm
	nasm -f $(FORMAT) project4.asm -o project4.obj

clean:
	$(RM) *.obj

cleanall: clean
	$(RM) *.exe
