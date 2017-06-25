#ifndef GESTION_NIVEAU_H_INCLUDED
#define GESTION_NIVEAU_H_INCLUDED

#include "init.h"

void collisionBriques(gameState *state, Balle *ball, Brique bricks[TABLE_WIDTH][TABLE_HEIGHT]);
enum BOOL niveauFini(gameState *state, Brique bricks[TABLE_WIDTH][TABLE_HEIGHT], Balle *ball);



#endif // GESTION_NIVEAU_H_INCLUDED
