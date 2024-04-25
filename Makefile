prog: main.o ennemi.o 
	gcc main.o ennemi.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g 
main.o:main.c	
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g 
ennemi.o: ennemi.c
	gcc -c ennemi.c -g
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g 
