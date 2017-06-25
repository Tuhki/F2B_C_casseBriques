#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

//Dimensions de l'écran
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 700
//Dimensions du tableau de briques
#define TABLE_WIDTH 12
#define TABLE_HEIGHT 6
//Dimensions de l'image contenant les briques
#define BRICK_IMAGE_WIDTH 128
#define BRICK_IMAGE_HEIGHT 48

//Définition d'un enum pour les trajectoires de balle et de raquette
typedef enum DIRECTION{

    HAUT,BAS,GAUCHE,DROITE,HD,HG,BG,BD,AUCUNE

}DIRECTION;

//Définition d'un enum booléen pour l'état des briques
typedef enum BOOL{

    TRUE,FALSE

}BOOL;

//Définition du type gérant le jeu dans une fenêtre avec SDL
typedef struct game{

     SDL_Window *g_Window;
     SDL_Renderer *g_Renderer;
     SDL_Texture *g_texture[2];
     SDL_Surface *g_surface;

}game;

//Définition du type gérant la partie en cours
typedef struct gameState{

    int g_bRunning;
    int left;
    int right;
    enum BOOL nextlevel;
    int numlevel;
    int life;
    int score;

}gameState;

//Définition du type avec les coordonnées
typedef struct Coordonnees{

    double x;
    double y;

}Coordonnees;

//Définition du type de la balle
typedef struct Balle{

    Coordonnees coord;
    double r;
    enum DIRECTION dir;
    int vitesse;
    enum BOOL contact;

}Balle;

//Définition du type de la raquette
typedef struct Raquette{

    Coordonnees coord;
    int w;
    int h;

}Raquette;

//Définition du type des briques
typedef struct Brique{

    SDL_Rect rectSource;
    SDL_Rect rectDest;
    enum BOOL visible;

}Brique;


int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame,Balle *ball, Raquette *raq, gameState *state, Brique tabBrick[TABLE_WIDTH][TABLE_HEIGHT]);
void chargeTexture(game *myGame);

#endif // INIT_H_INCLUDED
