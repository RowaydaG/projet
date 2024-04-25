#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include <time.h>
#include "perso.h"

int main()
{
	Uint32 dt ,t_prev; 
	int hauteur_fenetre = 800,t,a=1,done=1,vi=1,sc=1,direction=0,sautt=0,
        	largeur_fenetre = 1200;
	
	SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);
//creation de la fenetre 
	SDL_Surface *screen;
	 if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
 	screen=SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }
  
	SDL_WM_SetCaption("PERSO", NULL); 
// creation background
 	SDL_Surface *backg;
	SDL_Rect backg_pos;
	backg = IMG_Load("background.jpg");
	backg_pos.x = 0;
	backg_pos.y = 0;

 //initialisation 

	Personne p;
	
	initPerso(&p);


	 while(done)
    {  
	t_prev=SDL_GetTicks();
    	SDL_PollEvent(&event);
 
     switch(event.type)

     {  
     	case SDL_QUIT: 
		done=0;
		break;
	case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {  
		case SDLK_s: 
               	direction=0;
               	movePerso(&p ,screen,direction);
		break;
		
		case SDLK_d: 
               	direction=1;
               	movePerso(&p ,screen,direction);
               	sautt=1;
               	                
		break;
			
		case SDLK_g: 
               	direction=2;
               	movePerso(&p ,screen,direction);
               	sautt=2;
               
		break;
		case SDLK_SPACE:
		direction=3;
               	movePerso(&p ,screen,direction);
			
		break;
		
		case SDLK_UP:
			vitesseUP(&p);
		break;
		
		case SDLK_DOWN:
			vitesseDOWN(&p);
		break;
               
		case SDLK_ESCAPE: 
              		done=0;
		break; 
		
            }
      
     }   

		SDL_BlitSurface(backg,NULL,screen,&backg_pos);
		afficherPerso (p,screen);
		if (sautt==1){	 
		saut(&p);
		}
		if (sautt==2){
		sautgauche(&p);
		}
		dt=SDL_GetTicks()-t_prev;
     		SDL_Flip(screen);
    }
	
	
	SDL_FreeSurface(backg);
	SDL_Quit();

    return 0;
}









