#ifndef BACKGROUND_H_INCLUDE
#define BACKGROUND_H_INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 1000
#define SCREEN_H 765

typedef struct
{
	SDL_Surface *img_b;
	SDL_Rect position_b;
	SDL_Rect position_collision;
	SDL_Rect camera_pos;
	SDL_Rect camera2_pos;
	Mix_Music *son;
	SDL_Surface *image_flower;  
	SDL_Rect pos_image_flower;
	SDL_Rect single_flower;	
	int flower_num;


}background;

void initialisation_back(background *b);
void initBack (background *b);
void initBackMasque (background *b);
void initBack2 (background *b);
void afficheBack (background b,SDL_Surface *screen);
void afficheBack2 (background b,SDL_Surface *screen);
void afficher_back(background b, SDL_Surface *screen);
void scrolling (background *b,int pas,int direction);
void displayFlower(background b,SDL_Surface *screen);
void animerBackground(background *b);
//void afficherBest(SDL_Surface *screen , ScoreInfo t[] );

#endif  
