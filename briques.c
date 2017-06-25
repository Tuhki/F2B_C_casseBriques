#include "briques.h"

void renderBrique(gameState *state, game *myGame, Brique bricks[TABLE_WIDTH][TABLE_HEIGHT]) {
//BUT    : Générer le tableau de briques
//ENTREE : Image contenant les briques
//SORTIE : Remplissage aléatoire du tableau de briques

        //Variables de boucles
        int i,j;
        //Variable pour la gestion de l'aléatoire
        int r;

        //Rectangles contenant l'image de la raquette
        SDL_Rect rectangleSource[4];

        if(myGame->g_texture[1]){

            /* Définition de chaque brique de couleur différente */

                //Zone de l'image contenant la brique voulue

                    //BRIQUE ROUGE
                    rectangleSource[0].x=0;
                    rectangleSource[0].y=0;
                    //Taille de la brique dans l'image
                    rectangleSource[0].w=BRICK_IMAGE_WIDTH/2;
                    rectangleSource[0].h=BRICK_IMAGE_HEIGHT/2;

                    //BRIQUE JAUNE
                    rectangleSource[1].x=BRICK_IMAGE_WIDTH/2;
                    rectangleSource[1].y=0;
                    //Taille de la brique dans l'image
                    rectangleSource[1].w=BRICK_IMAGE_WIDTH/2;
                    rectangleSource[1].h=BRICK_IMAGE_HEIGHT/2;

                    //BRIQUE VERTE
                    rectangleSource[2].x=0;
                    rectangleSource[2].y=BRICK_IMAGE_HEIGHT/2;
                    //Taille de la brique dans l'image
                    rectangleSource[2].w=BRICK_IMAGE_WIDTH/2;
                    rectangleSource[2].h=BRICK_IMAGE_HEIGHT/2;

                    //BRIQUE BLEUE
                    rectangleSource[3].x=BRICK_IMAGE_WIDTH/2;
                    rectangleSource[3].y=BRICK_IMAGE_HEIGHT/2;
                    //Taille de la brique dans l'image
                    rectangleSource[3].w=BRICK_IMAGE_WIDTH/2;
                    rectangleSource[3].h=BRICK_IMAGE_HEIGHT/2;

            //Appel de la texture
            SDL_QueryTexture(myGame->g_texture[1],NULL,NULL,NULL,NULL);

            //Répartition aléatoire des briques dans le tableau

            for(i=0 ; i < (TABLE_WIDTH) ; i++){

                for(j=0 ; j < (TABLE_HEIGHT) ; j++){

                    r = rand() % 4;
                    bricks[i][j].rectSource = rectangleSource[r];
                    bricks[i][j].rectDest = rectangleSource[r];
                    bricks[i][j].rectDest.x = i*BRICK_IMAGE_WIDTH/2 +BRICK_IMAGE_WIDTH;
                    bricks[i][j].rectDest.y = j*BRICK_IMAGE_HEIGHT/2 +BRICK_IMAGE_HEIGHT*2;
                    bricks[i][j].visible = TRUE;

                    if(state->numlevel > 0){

                        r = rand() % 10;
                        if(r%2 == 0){

                            bricks[i][j].visible = FALSE;

                        }

                    }

                }

            }

            state->nextlevel = FALSE;
            state->numlevel = 0;

        }else{
                fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
        }

}

void afficheBriques(game *myGame, Brique bricks[TABLE_WIDTH][TABLE_HEIGHT]){
//BUT    : Afficher les briques
//ENTREE : Tableau de briques
//SORTIE : Affichage des briques comme définies dans le tableau

    int i,j;

    for(i=0 ; i < (TABLE_WIDTH) ; i++){

        for(j=0 ; j < (TABLE_HEIGHT) ; j++){

            if(bricks[i][j].visible == TRUE){

                SDL_RenderCopy(myGame->g_Renderer,myGame->g_texture[1],&bricks[i][j].rectSource,&bricks[i][j].rectDest);

            }

        }

    }

}

