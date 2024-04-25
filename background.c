#include "background.h"

void initBack (background *b)
{
//background
b->img_b=IMG_Load("back.bmp");
b->position_b.x=0;
b->position_b.y=0;
//camera
b->camera_pos.x=0;
b->camera_pos.y=0;
b->camera_pos.w=SCREEN_W; 
b->camera_pos.h=SCREEN_H;
//musique
b->son=Mix_LoadMUS("musique.mp3"); 
}

void initBackMasque (background *b)
{
//background
b->img_b=SDL_LoadBMP("backmasque.bmp");
b->position_b.x=0;
b->position_b.y=0;
//camera
b->camera_pos.x=0;
b->camera_pos.y=0;
b->camera_pos.w=SCREEN_W; 
b->camera_pos.h=SCREEN_H;

}

void initBack2 (background *b)
{
//background2
b->img_b=IMG_Load("back.bmp");
b->position_collision.x=0;
b->position_collision.y=0;
//camera2
b->camera2_pos.x=0;
b->camera2_pos.y=0;
b->camera2_pos.w=SCREEN_W; 
b->camera2_pos.h=SCREEN_H;
//musique
b->son=Mix_LoadMUS("musique.mp3"); 
	b->image_flower=IMG_Load("flower.png");  
	b->pos_image_flower.x=850;
	b->pos_image_flower.y=270;
	
	b->single_flower.w=56;
	b->single_flower.h=107;
	b->single_flower.x=0;
	b->single_flower.y=0;

	b->flower_num=0;

}


void initialisation_back(background *b)
{
	initBack(b);	
	initBack2(b);
}



void afficheBack (background b, SDL_Surface *ecran)
{
Mix_PlayMusic(b.son, -1);
SDL_BlitSurface(b.img_b,&b.camera_pos,ecran,&b.position_b);
}

void afficheBack2 (background b, SDL_Surface *ecran)
{
Mix_PlayMusic(b.son, -1); 
SDL_BlitSurface(b.img_b,&b.camera2_pos,ecran,&b.position_collision);
displayFlower(b,ecran);

}
void afficher_back(background b, SDL_Surface *ecran)
{
	afficheBack(b,ecran);
	afficheBack2(b,ecran);
	
}

void scrolling (background *b,int pas,int direction)
{

if (direction ==0){  
	b->camera_pos.x+= pas;          
	b->camera2_pos.x+= pas;
        }
else if (direction ==1){          
	b->camera_pos.x-=pas; 
	b->camera2_pos.x-=pas; 
	}
else if (direction ==2){
        b->camera_pos.y-= pas;
        b->camera2_pos.y-= pas;
	}
else if (direction ==3){          
        b->camera_pos.y+= pas;
	b->camera2_pos.y+= pas;
	}
}


void displayFlower(background b,SDL_Surface *ecran){
			
 		SDL_BlitSurface(b.image_flower,&(b.single_flower), ecran, &b.pos_image_flower);
}
void animerBackground(background *b){
		 	
	if (b->flower_num >=0 && b->flower_num <8) {
	b->single_flower.x=b->flower_num * b->single_flower.w;
	b->flower_num++;
	}
	
	if ( b->flower_num == 8) {
	b->single_flower.x=b->flower_num * b->single_flower.w;
	b->flower_num=0;
	}
 
	 
}
