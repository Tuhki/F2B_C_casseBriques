#include "raquette.h"

void renderRaquette(game *myGame, Raquette raq) {
//BUT    : Afficher la raquette
//ENTREE : Image de la raquette
//SORTIE : Affichage de l'image de la raquette

        //Rectangles contenant l'image de la raquette
        SDL_Rect rectangleDest;
        SDL_Rect rectangleSource;

                if(myGame->g_texture[2]){

                    //Rectangle contenant l'image
                    rectangleSource.x=0;
                    rectangleSource.y=0;
                    rectangleSource.w=128;
                    rectangleSource.h=32;
                    SDL_QueryTexture(myGame->g_texture[2],NULL,NULL,NULL,NULL);

                    //Définition du rectangle dest pour dessiner Bitmap
                    rectangleDest.x=raq.coord.x;//debut x
                    rectangleDest.y=raq.coord.y;//debut y
                    rectangleDest.w=raq.w; //Largeur
                    rectangleDest.h=raq.h; //Hauteur

                    // Affichage
                    SDL_RenderCopy(myGame->g_Renderer,myGame->g_texture[2],&rectangleSource,&rectangleDest);

                }

                else{
                        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }

}

void mouvRaquette(gameState *state, Raquette *raq){
//BUT    : Déplacer la raquette
//ENTREE : Direction de la raquette
//SORTIE : Mouvement de la raquette

    //La raquette se déplace vers la gauche
    if (state->left == 1){

        raq->coord.x --;

    }

    //La raquettese déplace vers la droite
    if (state->right == 1){

        raq->coord.x ++;

    }

}

void placeRaquette(gameState *state, Raquette *raq){
//BUT    : Corriger la position de la raquette
//ENTREE : Inputs joueur
//SORTIE : Correction de la position de la raquette

    //Si le joueur veut aller à gauche mais que la raquette est au bord gauche de l'écran
    if (((state->left == 1)&&((raq->coord.x-1) <= 0))
    //Ou que le joueur veut aller à droite mais que la raquette est au bord droit de l'écran
    || ((state->right == 1)&&((raq->coord.x + raq->w) >= SCREEN_WIDTH ))){

        //On arrête le mouvement de la raquette
        state->left = 0;
        state->right = 0;

    }


    //Si la raquette dépasse le bord gauche de l'écran
    if(raq->coord.x < 0){

        //On la remet dans l'écran
        raq->coord.x = 0;

    }

    //Si la raquette dépasse le bord droit de l'écran
    if((raq->coord.x + raq->w) > SCREEN_WIDTH){

        //On la remet dans l'écran
        raq->coord.x = SCREEN_WIDTH - raq->w;

    }

}
