#include "balle.h"

void renderBalle(game *myGame,gameState state, Balle ball) {
//BUT    : Afficher la balle
//ENTREE : Image de la balle
//SORTIE : Affichage de l'image

        //Rectangles contenant l'image de la balle
        SDL_Rect rectangleDest;
        SDL_Rect rectangleSource;


                if(myGame->g_texture[0]){

                    //Rectangle contenant l'image
                    rectangleSource.x=0;
                    rectangleSource.y=0;
                    rectangleSource.w=24;
                    rectangleSource.h=24;
                    SDL_QueryTexture(myGame->g_texture[0],NULL,NULL,NULL,NULL);

                    //Définition du rectangle dest pour dessiner Bitmap
                    rectangleDest.x=ball.coord.x;//debut x
                    rectangleDest.y=ball.coord.y;//debut y
                    rectangleDest.w=ball.r; //Largeur
                    rectangleDest.h=ball.r; //Hauteur

                    // Affichage
                    SDL_RenderCopy(myGame->g_Renderer,myGame->g_texture[0],&rectangleSource,&rectangleDest);

                }

                else{
                        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }

}

void mouvBalle(Balle *ball,Raquette raq){
//BUT    : Changer le mouvement de la balle
//ENTREE : Direction de la balle
//SORTIE : Modification du mouvement de la balle

    //Vers le bas et droite
    if(ball->dir == BD){

        ball->coord.y++;
        ball->coord.x++;

    }

    //Vers le haut et droite
    if(ball->dir == HD){

        ball->coord.y--;
        ball->coord.x++;

    }

    //Vers le bas et gauche
    if(ball->dir == BG){

        ball->coord.y++;
        ball->coord.x--;

    }

    //Vers le haut et gauche
    if(ball->dir == HG){

        ball->coord.y--;
        ball->coord.x--;

    }

    //La balle ne se déplace pas
    if(ball->dir == AUCUNE){

        ball->coord.y = raq.coord.y - ball->r;
        ball->coord.x = raq.coord.x + raq.w/2 - ball->r/3;

    }

    //La balle se déplace à la verticale vers le haut
    if(ball->dir == HAUT){

        ball->coord.y--;

    }

    //La balle se déplace à la verticale vers le bas
    if(ball->dir == BAS){

        ball->coord.y++;

    }

}

void placeBalle(Balle *ball, Raquette *raq, gameState *state){
//BUT    : Changer la direction de la balle
//ENTREE : Coordonnées de la balle
//SORTIE : Changement de direction

    //Si la balle touche la raquette en venant de droite
    if((((ball->coord.y + ball->r) >= (SCREEN_HEIGHT - raq->h))&&(ball->dir == BD)&&(ball->coord.x >= raq->coord.x)&&(ball->coord.x <= (raq->coord.x + raq->w)))
       //OU touche la gauche en venant de bas
       ||((ball->coord.x <= 0) && (ball->dir == HG))){

        ball->dir = HD;

    }

    //Si la balle touche la raquette en venant de gauche
    if((((ball->coord.y + ball->r) >= (SCREEN_HEIGHT - raq->h))&&(ball->dir == BG)&&(ball->coord.x >= raq->coord.x)&&(ball->coord.x <= (raq->coord.x + raq->w)))
       //OU touche la droite ou une brique en venant du bas
       ||((ball->coord.x >= SCREEN_WIDTH - ball->r) && (ball->dir == HD))){

        ball->dir = HG;

    }

     //Si la balle touche le haut de l'écran ou une brique en venant de droite
    if((((ball->coord.y <= 0)||(ball->contact == TRUE))&&(ball->dir == HG))
       //OU touche la droite en venant du haut
       ||(((ball->coord.x >= SCREEN_WIDTH - ball->r)||(ball->contact == TRUE))&& (ball->dir == BD))){

            ball->dir = BG;
            ball->contact = FALSE;

    }

     //Si la balle touche la gauche de l'écran ou une brique en venant du haut
    if((((ball->coord.x <= 0)||(ball->contact == TRUE)) && (ball->dir == BG))
        //OU touche le haut de l'écran ou une brique en venant de gauche
        ||(((ball->coord.y <= 0)||(ball->contact == TRUE))&&(ball->dir == HD))){

            ball->dir = BD;
            ball->contact = FALSE;

    }

    //Le joueur ne réussit pas à rattraper la balle
    if(ball->coord.y >= SCREEN_HEIGHT){

        ball->dir = AUCUNE;
        state->life--;
        printf("Vie(s) restante(s) : %i\n", state->life);

    }

    //La balle vient d'être lancée et touche une brique ou le haut de l'écran
    if((ball->dir == HAUT)&&((ball->contact == TRUE)||(ball->coord.y <= 0))){

        ball->dir = BAS;

    }

    //La balle attérit verticalement sur la partie gauche de la raquette
    if((ball->dir == BAS)
       &&((ball->coord.x + ball->r/2) >= raq->coord.x)
       &&((ball->coord.x + ball->r/2) < (raq->coord.x + raq->w/2))
       &&(ball->coord.y >= raq->coord.y - ball->r)){

        ball->dir = HG;

    }

    //La balle attérit verticalement sur la partie droite de la raquette
    if((ball->dir == BAS)
       &&((ball->coord.x + ball->r/2) >= (raq->coord.x + raq->w/2))
       &&((ball->coord.x + ball->r/2) <= (raq->coord.x + raq->w))
       &&(ball->coord.y >= raq->coord.y - ball->r)){

        ball->dir = HD;

    }

    /* ne fonctionnait pas...

    //La balle attérit verticalement au centre de la raquette
    if((ball->dir == BAS)
        &&(ball->coord.y >= raq->coord.y - ball->r)){

        ball->dir = HAUT;

    }
    */

}
