#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 563
#define SCREEN_W 1000
typedef struct
{
char *ur1;
SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran;
SDL_Surface *img;
}image;

typedef struct
{
char *ur1m;
SDL_Surface *img_miniature;
SDL_Rect pos_map_ecran;
char *ur1p;
SDL_Surface *joueur_miniature;
SDL_Rect pos_joueur_miniature_map;
}minimap;


typedef struct{
SDL_Rect posScreen;
SDL_Surface * image_actuelle;

int direction;
double acceleration;
}personne;

typedef struct {
    SDL_Rect rect; 
    SDL_Surface* surface; 
} Obstacle;


void initmap (minimap *m);
void initialiser_imageBACK(image *IMAGE);
void iniPerso(personne *p);
void afficherminimap (minimap m , SDL_Surface *screen );
int collisionPP (personne p, SDL_Surface * surface );
int animerminimap (minimap * m);
void MAJMinimap (personne p, minimap *m,SDL_Rect camera, int redimensionnement );
void afficherPerso(personne p, SDL_Surface * screen);
void affiche_image(SDL_Surface *screen,image IMAGE);
void liberer_image(image IMAGE);
void liberer_personne(personne p);
void movePerso(personne *pers );
void liberer (minimap m);


#endif
