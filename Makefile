all: tests.exe donors.exe

donors.exe:dynarr.o donors.c
	gcc donors.c dynarr.o -o donors.exe

tests.exe: dynarr.o tests.c
	gcc tests.c dynarr.o -o tests.exe

dynarr.o: dynarr.h dynarr.c
	gcc -c dynarr.c -o dynarr.o

clean:
	del *.exe *.o