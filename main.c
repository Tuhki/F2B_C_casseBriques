#include "init.h"
#include "balle.h"
#include "destruction.h"
#include "raquette.h"
#include "events.h"
#include "briques.h"
#include "gestion_niveau.h"

int main(int argc, char *argv[]){
//BUT   : Créer un jeu casse-briques avec la SDL et des images
//ENTREE: inputs joueurs, assets
//SORTIE: gestion du casse-briques

    //On crée les différents éléments du jeu
    game myGame;
    gameState state;
    Balle ball;
    Raquette raq;
    Brique tabBrick[TABLE_WIDTH][TABLE_HEIGHT];

    //Pour les 60 fps
    unsigned int frameLimit = SDL_GetTicks() + 16;

    //On initialise les éléments du jeu
    if(init("Casse-Briques",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame,&ball,&raq,&state,tabBrick)){

            //On charge les textures
            chargeTexture(&myGame);

            //Si tout s'est bien passé, on lance le jeu
            state.g_bRunning=1;

    }else{

            //Si tout ne s'est pas bien passé on retourne une valeur d'erreur
            return 1;

    }

    //Tant que le jeu est en route, on appelle les procédures qui le gèrent
    while(state.g_bRunning){

        //Lancement du niveau
        if(state.nextlevel == TRUE){
            printf("Vie(s) restante(s) : %i\n", state.life);
            //Remplissage du tableau avec les briques
            renderBrique(&state,&myGame,tabBrick);

        }

        //On gère les évènements utilisateurs
        handleEvents(&state, &ball, &raq, tabBrick);

        //On gère la balle
        renderBalle(&myGame,state,ball);
        placeBalle(&ball,&raq,&state);
        mouvBalle(&ball,raq);

        //On gère la raquette
        renderRaquette(&myGame,raq);
        placeRaquette(&state,&raq);
        mouvRaquette(&state,&raq);

        //On gère les briques
        afficheBriques(&myGame,tabBrick);
        collisionBriques(&state,&ball,tabBrick);

        //On gère l'avancement du niveau
        state.nextlevel = niveauFini(&state, tabBrick, &ball);

        //Affichage des différentes images
        SDL_RenderPresent(myGame.g_Renderer);

        //On nettoie l'écran
        SDL_RenderClear(myGame.g_Renderer);

        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit + ball.vitesse);
        frameLimit = SDL_GetTicks();

    }

    //On détruit les textures et les éléments du jeu, on quitte la SDL
    destroyTexture(&myGame);
    destroy(&myGame);
    SDL_Quit();

    //Tout s'est bien passé
    return 0;

};
