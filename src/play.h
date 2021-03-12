#ifndef PLAY_H
#define PLAY_H

struct GameState {
    int num_piles;
    int *restrict piles;
};

struct GameMove {
    int pile;
    int counters;
};

enum opponent_type {HUMAN, COMPUTER};

// Begin a game of Nim
void play(enum opponent_type opponent);

#endif
