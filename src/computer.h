#ifndef COMPUTER_H
#define COMPUTER_H

#include "play.h"

void comp_move(const struct GameState *restrict game,
               struct GameMove *restrict move);

#endif
