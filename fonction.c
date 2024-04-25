#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "header.h"

 
void initmap (minimap *m)
{
m->ur1m="minimap+obs.png";
m->img_miniature=IMG_Load(m->ur1m);
if (m->img_miniature==NULL)
{printf("unable to load background image %s \n",SDL_GetError());
}
m->pos_map_ecran.x=800;
m->pos_map_ecran.y=0;


m->ur1p="recja.png";
m->joueur_miniature=IMG_Load(m->ur1p);
if (m->joueur_miniature==NULL)
{printf("unable to load background image %s \n",SDL_GetError());
}
m->pos_joueur_miniature_map.x=825;
m->pos_joueur_miniature_map.y=74;
}

void initialiser_imageBACK(image *IMAGE)
{
IMAGE->ur1="background + obst.png";
IMAGE->img=IMG_Load(IMAGE->ur1);
if (IMAGE->img==NULL)
{printf("unable to load background image %s \n",SDL_GetError());
}
IMAGE->pos_img_ecran.x=0;
IMAGE->pos_img_ecran.y=0;
IMAGE->pos_img_affiche.x=0;
IMAGE->pos_img_affiche.y=0;
IMAGE->pos_img_affiche.h=563;
IMAGE->pos_img_affiche.w=1000;

}
void afficherminimap (minimap m , SDL_Surface *screen )
{
SDL_BlitSurface(m.img_miniature ,NULL ,screen , &m.pos_map_ecran);
SDL_BlitSurface(m.joueur_miniature,NULL,screen,&m.pos_joueur_miniature_map);
}
void liberer (minimap m)
{
SDL_FreeSurface(m.img_miniature);
}

void affiche_image(SDL_Surface *screen,image IMAGE)
{
SDL_BlitSurface(IMAGE.img , &IMAGE.pos_img_affiche ,screen , &IMAGE.pos_img_ecran);
}
void liberer_image(image IMAGE)
{
SDL_FreeSurface(IMAGE.img);
}

void iniPerso(personne *p)
{
p->image_actuelle=IMG_Load("perso.png");
p->posScreen.x=6;
p->posScreen.y=230;
}
void afficherPerso(personne p, SDL_Surface * screen)
{
SDL_BlitSurface(p.image_actuelle,NULL,screen,&p.posScreen);
}
void liberer_personne(personne p)
{
SDL_FreeSurface(p.image_actuelle);

}

void movePerso(personne *pers)
{
	if(pers->direction==0)
	{
		pers->posScreen.x+=20*pers->acceleration;
	}
	if(pers->direction==1)
	{
		pers->posScreen.x-=20*pers->acceleration;
	}
	if(pers->acceleration<1)
	{
		pers->acceleration+=0.1;
	}
}



void MAJMinimap(personne p, minimap *m, SDL_Rect camera, int redimensionnement) {
    SDL_Rect posJoueurABS;
 
    posJoueurABS.x = p.posScreen.x;
    posJoueurABS.y = p.posScreen.y; 

    if (m->pos_joueur_miniature_map.x > 0) {
        m->pos_joueur_miniature_map.x = (posJoueurABS.x * 20 / 100) + 825;
        m->pos_joueur_miniature_map.y = (posJoueurABS.y * 20 / 100) + 28 ;
    } 
}

	



SDL_Color GetPixel(SDL_Surface *pSurface,int x, int y)
{
SDL_Color color;
Uint32 col=0;
char* pPosition=(char*)pSurface->pixels;
pPosition+=(pSurface->pitch*y);
pPosition+=(pSurface->format->BytesPerPixel *x);
memcpy(&col,pPosition,pSurface->format->BytesPerPixel);
SDL_GetRGB(col,pSurface->format,&color.r,&color.g,&color.b);
return (color);
}



int collisionPP(personne p, SDL_Surface* Masque) {
    int collision = 0;  
    for(int i = 1; i <= 8; i++) {
        int x = p.posScreen.x, y = p.posScreen.y, w = p.posScreen.w, h = p.posScreen.h;
        switch(i) {
            case 1: 
		x = p.posScreen.x; y = p.posScreen.y;
		break;
            case 2:
		x = p.posScreen.x + w/2; y = p.posScreen.y;
		break;
            case 3:
		x = p.posScreen.x + w; y = p.posScreen.y; 
		break;
            case 4: 
		x = p.posScreen.x; y = p.posScreen.y + h/2;
		break;
            case 5:
		x = p.posScreen.x; y = p.posScreen.y + h;
		break;
            case 6: 
		x = p.posScreen.x + w/2; y = p.posScreen.y + h;
		break;
            case 7:
		x = p.posScreen.x + w; y = p.posScreen.y + h;
		break;
            case 8:
		x = p.posScreen.x + w; y = p.posScreen.y + h/2;
		break;
        }
        SDL_Color pixelColor = GetPixel(Masque, x, y);
        
        if (pixelColor.r == 0 && pixelColor.g == 0 && pixelColor.b == 0) {
            collision = 1;  
            break;  
        }
    }
    return collision;  
}



