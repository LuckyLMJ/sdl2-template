all:
	gcc -I SDL2/include -L SDL2/lib -o main main.c -lmingw32 -lSDL2main -lSDL2
	./main.exe