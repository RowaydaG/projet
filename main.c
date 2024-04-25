#include "ennemi.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    if (!screen)
    {
        printf("Erreur lors de l'initialisation de la SDL\n");
        return EXIT_FAILURE;
    }

    Ennemi ennemi;
    initEnnemi(&ennemi);

    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        }

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); // Efface l'écran avec du blanc
        moveEnnemi(&ennemi); // Déplace l'ennemi
        animerEnnemi(&ennemi); // Anime l'ennemi
        afficherEnnemi(ennemi, screen); // Affiche l'ennemi sur l'écran
        SDL_Flip(screen); // Rafraîchit l'écran
    }

    SDL_Quit();
    return EXIT_SUCCESS;
}

