windows:
	gcc -Wall -02 -I SDL2/include -L SDL2/lib -o main main.c -lmingw32 -lSDL2main -lSDL2 -mwindows
	./main.exe
linux:
	gcc -Wall -O2 -o main main.c -lSDL2
	./main