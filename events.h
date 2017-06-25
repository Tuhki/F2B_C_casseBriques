#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

#include "init.h"

void handleEvents(gameState *state, Balle *ball, Raquette *raq, Brique bricks[TABLE_WIDTH][TABLE_HEIGHT]);
int delay(unsigned int frameLimit);

#endif // EVENTS_H_INCLUDED
