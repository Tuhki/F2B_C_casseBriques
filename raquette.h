#ifndef RAQUETTE_H_INCLUDED
#define RAQUETTE_H_INCLUDED

#include "init.h"

void renderRaquette(game *myGame, Raquette raq);
void mouvRaquette(gameState *state, Raquette *raq);
void placeRaquette(gameState *state, Raquette *raq);

#endif // RAQUETTE_H_INCLUDED
