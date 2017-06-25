#ifndef BRIQUES_H_INCLUDED
#define BRIQUES_H_INCLUDED

#include "init.h"

void renderBrique(gameState *state, game *myGame, Brique bricks[TABLE_WIDTH][TABLE_HEIGHT]);
void afficheBriques(game *myGame, Brique bricks[TABLE_WIDTH][TABLE_HEIGHT]);

#endif // BRIQUES_H_INCLUDED
