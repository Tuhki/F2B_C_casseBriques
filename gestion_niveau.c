#include "gestion_niveau.h"

void collisionBriques(gameState *state, Balle *ball, Brique bricks[TABLE_WIDTH][TABLE_HEIGHT]){
//BUT    : Gérer les collisions de la balle avec les briques
//ENTREE : Position de la balle
//SORTIE : Disparition des briques

    int i,j;

    for(i=0; i<TABLE_WIDTH ; i++){

        for(j=0; j<TABLE_HEIGHT ; j++){

            //Si la balle touche une brique
            if( ((ball->coord.x + ball->r/2) >= bricks[i][j].rectDest.x)
                && ((ball->coord.x + ball->r/2) <= (bricks[i][j].rectDest.x+bricks[i][j].rectDest.w))
                && (ball->coord.y >= bricks[i][j].rectDest.y)
                && (ball->coord.y <= (bricks[i][j].rectDest.y+bricks[i][j].rectDest.h))
                && (bricks[i][j].visible == TRUE)){

                    //La brique disparait, le score augmente
                    bricks[i][j].visible = FALSE;
                    state->score++;
                    ball->contact = TRUE;

            }

        }

    }

}

enum BOOL niveauFini(gameState *state, Brique bricks[TABLE_WIDTH][TABLE_HEIGHT], Balle *ball){
//BUT    : Gérer la fin d'un niveau
//ENTREE : Etat du tableau de briques et du jeu
//SORTIE : Passage au niveau suivant

    int i,j;

    //Si le joueur utilise sa dernière vie
    if(state->life < 0){

        //Il perd, on met fin au jeu
        state->g_bRunning = 0;
        printf("Perdu !");
        return FALSE;

    }

    //Pendant la partie, on vérifie les briques cassées
    for(i=0; i<TABLE_WIDTH; i++){

        for(j=0; j<TABLE_HEIGHT; j++){

            //S'il y a au moins une brique encore visible...
            if(bricks[i][j].visible == TRUE){

                //... la partie continue
                return FALSE;

            }

        }

    }

    //Sinon, si toutes les briques ont été détruites, on passe au niveau suivant
        //On remet la balle sur la raquette
        ball->dir = AUCUNE;

        //Si le joueur n'a pas fini tous les niveaux
        if(ball->vitesse > 0){

            //Augme,tation de la vitesse de la balle
            ball->vitesse--;

            //Augmentation du niveau
            state->numlevel++;

            //Réinitialisation de la vie
            state->life = 3;

            system("cls");
            printf("Votre score : %i\n",state->score);
            printf("Niveau suivant !\n");

        //Si la vitesse atteint son maximum...
        }else if(ball->vitesse == 0){

            //... Le joueur a gagné
            state->g_bRunning = 0;
            system("cls");
            printf("\nBravo ! Vous avez fini tous les niveaux !\n");
            return FALSE;

        }

    return TRUE;

}


