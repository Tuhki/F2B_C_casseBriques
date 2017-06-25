#include "init.h"

int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame,Balle *ball, Raquette *raq, gameState *state, Brique tabBrick[TABLE_WIDTH][TABLE_HEIGHT]){
//BUT   : Initialisation des objets du casse-briques
//ENTREE: Objets déclarés dans le main
//SORTIE: Initialisation du jeu

    int i,j;

    //initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
            //On crée la fenêtre
            myGame->g_Window=SDL_CreateWindow(title,xpos,ypos,height,width,flags);

            //Si la fenêtre a été créée on crée le contenu dela fenêtre
            if(myGame->g_Window!=NULL){
                myGame->g_Renderer=SDL_CreateRenderer(myGame->g_Window,-1,SDL_RENDERER_ACCELERATED);
                SDL_SetRenderDrawColor(myGame->g_Renderer, 4, 5, 16, 255);
                SDL_RenderClear(myGame->g_Renderer);

                //Initialisation de la balle
                ball->coord.x = SCREEN_WIDTH/2;
                ball->coord.y = SCREEN_HEIGHT/2;
                ball->r = 18;
                ball->dir = AUCUNE;
                ball->vitesse = 7; //0 = rapide , 16 = lent
                ball->contact = FALSE;

                //Initialisation de la raquette
                raq->h = 32;
                raq->w = 128;
                raq->coord.x = 0;
                raq->coord.y = SCREEN_HEIGHT-raq->h;

                //Initialisation de la direction de la raquette et du numéro de niveau
                state->right=0;
                state->left=0;
                state->nextlevel=TRUE;
                state->numlevel=-1;
                state->life=3;
                state->score=0;

                //Initialisation du tableau de briques
                for(i=0 ; i < (TABLE_WIDTH) ; i++){

                    for(j=0 ; j < (TABLE_HEIGHT) ; j++){

                        //Initialisation du rectangle source (image)
                        tabBrick[i][j].rectSource.x = 0;
                        tabBrick[i][j].rectSource.y = 0;
                        tabBrick[i][j].rectSource.h = 0;
                        tabBrick[i][j].rectSource.w = 0;
                        //Initialisation du rectangle de destination de l'image
                        tabBrick[i][j].rectDest.x = 0;
                        tabBrick[i][j].rectDest.y = 0;
                        tabBrick[i][j].rectDest.h = 0;
                        tabBrick[i][j].rectDest.w = 0;
                        //Visible par défaut
                        tabBrick[i][j].visible = TRUE;

                    }

                }

            }

    }else{

        return 0;
    }

    return 1;

}

void chargeTexture(game *myGame){
//BUT : Charger les différentes textures dans un tableau pour ne les charger qu'une fois
//ENTREE : Images à charger
//SORTIE : Textures prêtes à l'usage

    //On utilise une surface temporaire
    SDL_Surface *temporarySurface;

    //On charge l'image de la balle dans le tableau des textures du jeu
    temporarySurface = IMG_Load("./Assets/ball.png");//Chargement de l'image png
    myGame->g_texture[0] = SDL_CreateTextureFromSurface(myGame->g_Renderer,temporarySurface); // Préparation du sprite
    SDL_FreeSurface(temporarySurface); // Libération de la ressource occupée par le sprite

     //On charge l'image des briques dans le tableau des textures du jeu
    temporarySurface = IMG_Load("./Assets/bricks.png");
    myGame->g_texture[1] = SDL_CreateTextureFromSurface(myGame->g_Renderer,temporarySurface);
    SDL_FreeSurface(temporarySurface);

     //On charge l'image de la raquette dans le tableau des textures du jeu
    temporarySurface = IMG_Load("./Assets/paddle.png");
    myGame->g_texture[2] = SDL_CreateTextureFromSurface(myGame->g_Renderer,temporarySurface);

    //On libère la surface temporaire
    SDL_FreeSurface(temporarySurface);


}
