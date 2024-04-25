prog:fonction.o main.o time.o
	gcc  main.o  fonction.o time.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
fonction.o:fonction.c
	gcc -c fonction.c -g
time.o:time.c
	gcc -c time.c -g


