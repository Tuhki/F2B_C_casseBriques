#include "destruction.h"

void destroy(game *myGame){
//BUT : D�truire l'instance de jeu
//ENTREE : Objet de type game
//SORTIE : Objet supprim�

    //Destroy render
    if(myGame->g_Renderer!=NULL){
         SDL_DestroyRenderer(myGame->g_Renderer);
    }

    //Destroy window
    if(myGame->g_Window!=NULL){
        SDL_DestroyWindow(myGame->g_Window);
    }

}

void destroyTexture(game *myGame){
//BUT : D�truire les textures
//ENTREE : Objet de type game
//SORTIE : Textures de l'objet supprim�es

    int i;

    //Destroy texture
    if(myGame->g_texture!=NULL){
        for(i=0;i<3;i++){
           SDL_DestroyTexture(myGame->g_texture[i]);
        }
    }

}




