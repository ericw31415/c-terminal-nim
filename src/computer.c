#include "computer.h"
#include <stdio.h>

void comp_move(const struct GameState *const restrict game,
               struct GameMove *const restrict move)
{
    puts("The computer is thinking...");

    int pile_xor = 0;
    for (int i = 0; i < game->num_piles; ++i)
        pile_xor ^= game->piles[i];

    if (pile_xor) {
        // Make the pile XOR 0
        for (int i = 0; i < game->num_piles; ++i) {
            if ((pile_xor ^ game->piles[i]) < game->piles[i]) {
                move->pile = i + 1;
                move->counters = game->piles[i] - (pile_xor ^ game->piles[i]);
                return;
            }
        }
    } else {
        // Losing position, so play the first available move
        for (int i = 0; i < game->num_piles; ++i) {
            if (game->piles[i] > 0) {
                move->pile = i + 1;
                move->counters = 1;
                return;
            }
        }
    }
}
