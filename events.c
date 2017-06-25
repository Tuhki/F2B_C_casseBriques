#include "events.h"

void handleEvents(gameState *state, Balle *ball, Raquette *raq, Brique bricks[TABLE_WIDTH][TABLE_HEIGHT]){
//BUT : Gérer les inputs utilisateurs
//ENTREE : Touches clavier appuyées
//SORTIE : Réaction du jeu aux touches

    SDL_Event event;
    int i,j;

    if(SDL_PollEvent(&event)){
        switch(event.type){

            //Le joueur quitte la fenêtre
            case SDL_QUIT:
                  state->g_bRunning=0;break;

            //Le joueur appuie sur une touche
            case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                        {
                            //Flèche gauche
                            case SDLK_LEFT:
                                state->left=1;
                                state->right=0;
                                break;

                            //Touche Q
                            case SDLK_q:
                                state->left=1;
                                state->right=0;
                                break;

                            //Flèche droite
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

            //Le joueur relâche une touche
            case SDL_KEYUP:
                state->left=0;
                state->right=0;
                break;

            //Le joueur peut déplacer la raquette avec la souris
            case SDL_MOUSEMOTION:
                if((event.motion.x >= 0) && (event.motion.x <= (SCREEN_WIDTH - raq->w))){

                    raq->coord.x = event.motion.x;
                    break;

                }

                break;

            //CHEAT MODE : sert à tester le jeu sans avoir à jouer tous les niveaux
            case SDL_MOUSEBUTTONDOWN:

                //En cas de clic droit
                if(event.button.button==3){

                    //On efface toutes les briques sauf la dernière colonne
                    for(i=0; i<TABLE_WIDTH-1; i++){

                        for(j=0; j<TABLE_HEIGHT; j++){

                                bricks[i][j].visible=FALSE;

                        }
                    }

                    //Si on n'est pas au dernier niveau
                    if(ball->vitesse>0){

                        //On efface entièrement la dernière colonne de briques
                        for(i=0; i<TABLE_HEIGHT; i++){

                            bricks[TABLE_WIDTH-1][i].visible=FALSE;

                        }

                    //Si on est au dernier niveau
                    }else{

                        //On prévient l'utilisateur
                        printf("\n In cheat mode : dernier niveau !\n");

                        //Et on efface la dernière colonne sauf une brique
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
//BUT : Gérer la framerate
//ENTREE : Vitesse de la balle
//SORTIE : Délai d'affichage

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
