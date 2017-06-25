#include "init.h"
#include "balle.h"
#include "destruction.h"
#include "raquette.h"
#include "events.h"
#include "briques.h"
#include "gestion_niveau.h"

int main(int argc, char *argv[]){
//BUT   : Cr�er un jeu casse-briques avec la SDL et des images
//ENTREE: inputs joueurs, assets
//SORTIE: gestion du casse-briques

    //On cr�e les diff�rents �l�ments du jeu
    game myGame;
    gameState state;
    Balle ball;
    Raquette raq;
    Brique tabBrick[TABLE_WIDTH][TABLE_HEIGHT];

    //Pour les 60 fps
    unsigned int frameLimit = SDL_GetTicks() + 16;

    //On initialise les �l�ments du jeu
    if(init("Casse-Briques",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame,&ball,&raq,&state,tabBrick)){

            //On charge les textures
            chargeTexture(&myGame);

            //Si tout s'est bien pass�, on lance le jeu
            state.g_bRunning=1;

    }else{

            //Si tout ne s'est pas bien pass� on retourne une valeur d'erreur
            return 1;

    }

    //Tant que le jeu est en route, on appelle les proc�dures qui le g�rent
    while(state.g_bRunning){

        //Lancement du niveau
        if(state.nextlevel == TRUE){
            printf("Vie(s) restante(s) : %i\n", state.life);
            //Remplissage du tableau avec les briques
            renderBrique(&state,&myGame,tabBrick);

        }

        //On g�re les �v�nements utilisateurs
        handleEvents(&state, &ball, &raq, tabBrick);

        //On g�re la balle
        renderBalle(&myGame,state,ball);
        placeBalle(&ball,&raq,&state);
        mouvBalle(&ball,raq);

        //On g�re la raquette
        renderRaquette(&myGame,raq);
        placeRaquette(&state,&raq);
        mouvRaquette(&state,&raq);

        //On g�re les briques
        afficheBriques(&myGame,tabBrick);
        collisionBriques(&state,&ball,tabBrick);

        //On g�re l'avancement du niveau
        state.nextlevel = niveauFini(&state, tabBrick, &ball);

        //Affichage des diff�rentes images
        SDL_RenderPresent(myGame.g_Renderer);

        //On nettoie l'�cran
        SDL_RenderClear(myGame.g_Renderer);

        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit + ball.vitesse);
        frameLimit = SDL_GetTicks();

    }

    //On d�truit les textures et les �l�ments du jeu, on quitte la SDL
    destroyTexture(&myGame);
    destroy(&myGame);
    SDL_Quit();

    //Tout s'est bien pass�
    return 0;

};
