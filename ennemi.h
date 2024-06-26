#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct Ennemi
{
        SDL_Surface *ennemi;
        SDL_Rect pos;
        SDL_Rect pos_sp;
        int direction;
        float speed;

} Ennemi;

void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e, SDL_Surface *screen);
void animerEnnemi(Ennemi *e);
void moveEnnemi(Ennemi *e);
int collisionBB_Ennemi(SDL_Rect E, SDL_Rect p);
void moveIAEnnemi(Ennemi *e, SDL_Rect pos_perso);

