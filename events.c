#include "events.h"

void handleEvents(gameState *state, Balle *ball, Raquette *raq, Brique bricks[TABLE_WIDTH][TABLE_HEIGHT]){
//BUT : G�rer les inputs utilisateurs
//ENTREE : Touches clavier appuy�es
//SORTIE : R�action du jeu aux touches

    SDL_Event event;
    int i,j;

    if(SDL_PollEvent(&event)){
        switch(event.type){

            //Le joueur quitte la fen�tre
            case SDL_QUIT:
                  state->g_bRunning=0;break;

            //Le joueur appuie sur une touche
            case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                        {
                            //Fl�che gauche
                            case SDLK_LEFT:
                                state->left=1;
                                state->right=0;
                                break;

                            //Touche Q
                            case SDLK_q:
                                state->left=1;
                                state->right=0;
                                break;

                            //Fl�che droite
                            case SDLK_RIGHT:
                                state->right=1;
                                state->left=0;
                                break;

                            //Touche D
                            case SDLK_d:
                                state->right=1;
                                state->left=0;
                                break;

                            //Le joueur lance la balle en appuyant sur la barre espace
                            case SDLK_SPACE:
                                if(ball->dir == AUCUNE){
                                    ball->dir = HAUT;
                                }
                                break;

                            //Si le joueur appuie sur la touche echap, on sort de la boucle du programme principal
                            case SDLK_ESCAPE:
                                state->nextlevel=TRUE;
                                system("cls");
                                printf("Au revoir.\n");
                                state->g_bRunning=0;
                                break;

                        }
                    break;

            //Le joueur rel�che une touche
            case SDL_KEYUP:
                state->left=0;
                state->right=0;
                break;

            //Le joueur peut d�placer la raquette avec la souris
            case SDL_MOUSEMOTION:
                if((event.motion.x >= 0) && (event.motion.x <= (SCREEN_WIDTH - raq->w))){

                    raq->coord.x = event.motion.x;
                    break;

                }

                break;

            //CHEAT MODE : sert � tester le jeu sans avoir � jouer tous les niveaux
            case SDL_MOUSEBUTTONDOWN:

                //En cas de clic droit
                if(event.button.button==3){

                    //On efface toutes les briques sauf la derni�re colonne
                    for(i=0; i<TABLE_WIDTH-1; i++){

                        for(j=0; j<TABLE_HEIGHT; j++){

                                bricks[i][j].visible=FALSE;

                        }
                    }

                    //Si on n'est pas au dernier niveau
                    if(ball->vitesse>0){

                        //On efface enti�rement la derni�re colonne de briques
                        for(i=0; i<TABLE_HEIGHT; i++){

                            bricks[TABLE_WIDTH-1][i].visible=FALSE;

                        }

                    //Si on est au dernier niveau
                    }else{

                        //On pr�vient l'utilisateur
                        printf("\n In cheat mode : dernier niveau !\n");

                        //Et on efface la derni�re colonne sauf une brique
                        for(i=0; i<TABLE_HEIGHT-1; i++){

                            bricks[TABLE_WIDTH-1][i].visible=FALSE;

                        }

                    }

                    break;

                }

            default: break;

        }
    }

}

int delay(unsigned int frameLimit){
//BUT : G�rer la framerate
//ENTREE : Vitesse de la balle
//SORTIE : D�lai d'affichage

    // Gestion des 60 fps (images/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return 0;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }

    return 0;
}
