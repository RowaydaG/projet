#include "perso.h"

void initPerso(Personne *p){

int vi,sc;
vi=initTextvie(&p->vie);
sc=initTextscore(&p->score);

(*p).image=IMG_Load("imagef.png");  

p->position.x=0;
p->position.y=700;

p->posSprite.w=100;
p->posSprite.h=100;
p->posSprite.x=0;
p->posSprite.y=0;

p->curSprite=0;
p->direction=0;


p->v_x =4 ;
p->v_grav =0.3;
p->v_saut = -6.5;
p->v_y = p->v_saut;

p->acceleration=0;
p->vitesse=5;

}

void afficherPerso (Personne p,SDL_Surface *screen){

	displayvie(p.vie,screen);
	displayscore(p.score,screen);
	SDL_BlitSurface(p.image,&(p.posSprite),screen,&(p.position));     
}


void movePerso(Personne *p ,SDL_Surface *screen,int direction){ 

	if (direction==0){
		while(p->position.y<700) 
   		{ 
     			p->position.y+=3;
    		}
    		p->direction=direction;
    		animerPerso(p);	
	}
	
	if (direction==1){
		p->position.x+=p->vitesse; 
		p->direction=direction;
		animerPerso(p);
	}
   	
 	if (direction==2){
   		p->position.x-=p->vitesse;
   		p->direction=direction;
   		animerPerso(p);	
	}
	
	if (direction==3){		 
		p->position.y-=2;  
	}
	
}


void animerPerso(Personne *p){
	/*p->posSprite.y = p->direction* p->posSprite.h ;

        if (p->posSprite.x =  p->posSprite.h =- p->posSprite.w ){ 

         p->posSprite.x  =0 ;
}

       else {
	p->posSprite.x  = p->posSprite.x  + p->posSprite.w;
	} //(avancer au frame suivant) */

   


	if(p->direction==1)
	{
		p->posSprite.y=0;
		p->curSprite++;
	if(p->curSprite>=4)
	{
		p->curSprite=0;
	}
		p->posSprite.x=p->curSprite * p->posSprite.w;  

	}	
	else
		if(p->direction==2)
		{ 
			p->posSprite.y=100;
			p->curSprite++;
		if(p->curSprite>=4)
		{
			p->curSprite=0;
		}
		p->posSprite.x=p->curSprite * p->posSprite.w;  
  
		}
	else 
		if(p->direction==0)
		{
			p->posSprite.x=0;

		}

}


void saut(Personne *p){

	if(p->position.y<700){
   	p->position.x += p->v_x;
   	p->position.y+= p->v_y;
   	p->v_y += p->v_grav;
   }
  	if (p->position.y> 700)
    	p->v_y = p->v_saut;
    	
}
void sautgauche(Personne *p){
	if(p->position.y<700){
   	p->position.x -= p->v_x;
   	p->position.y+= p->v_y;
   	p->v_y += p->v_grav;
   }
  	if (p->position.y> 700)
    	p->v_y = p->v_saut;


}

void vitesseUP(Personne *p){
	 p->acceleration +=0.05;
	p->vitesse+=p->acceleration ;
	if(p->vitesse>=30)
         {
          p->vitesse=30;
         }
       
        }
void vitesseDOWN(Personne *p){
	p->acceleration -=0.01;
	p->vitesse-=p->acceleration; 	
	if (p->vitesse<0) 
 	p->vitesse=0;
	
	
	
}



/*void freesurface(SDL_Surface *p,SDL_Surface *screen){

	SDL_FreeSurface(p->image);

}
*/
























