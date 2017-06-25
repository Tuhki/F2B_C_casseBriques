#ifndef BALLE_H_INCLUDED
#define BALLE_H_INCLUDED

#include "init.h"

void renderBalle(game *myGame,gameState state, Balle ball);
void mouvBalle(Balle *ball, Raquette raq);
void placeBalle(Balle *balle, Raquette *raq, gameState *state);

#endif // BALLE_H_INCLUDED
