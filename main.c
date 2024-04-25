#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "header.h"
#include "time.h"
int main()
{
SDL_Surface *SCREEN;
SDL_Rect camera;
image IMAGE1;
minimap m;
personne p;
SDL_Event event;


char buffer[32];
int x;
int redimensionnement;
int done=1;
int boucle=1;
Time temps;
SDL_Surface *screen =NULL;
    SDL_Init(SDL_INIT_EVERYTHING);
    screen=SDL_SetVideoMode(800,600, 32,SDL_HWSURFACE| SDL_DOUBLEBUF);
    SDL_WM_SetCaption("game",NULL);

if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO| SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n",SDL_GetError());
return -1;
}

SCREEN=SDL_SetVideoMode(1000 , 563 ,32 , SDL_SWSURFACE |SDL_DOUBLEBUF);
inittemps(&temps);
initialiser_imageBACK(&IMAGE1);
iniPerso(&p);
initmap (&m);


while(done)
{	
	update_time(&temps);
	affiche_image(SCREEN,IMAGE1);
	afficherminimap (m ,SCREEN );
	afficherPerso(p,SCREEN);
	displaytime(temps,screen);
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
			done=0;
			break;

			case SDL_KEYDOWN:

				switch(event.key.keysym.sym)
				{
					case SDLK_RIGHT:
					p.direction=0;
					movePerso(&p);
					MAJMinimap( p, & m,  camera, redimensionnement);
					break;
					case SDLK_LEFT:
					p.direction=1;
					movePerso(&p);
					MAJMinimap( p, & m,  camera, redimensionnement);
					
					break;
				}
	
					
			
		}

	}
	SDL_Flip(SCREEN);
	SDL_Delay(100);
}
liberer_image(IMAGE1);
liberer (m);
liberer_personne(p);

SDL_Quit();
return 0;
}








