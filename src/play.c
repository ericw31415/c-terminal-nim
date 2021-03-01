#include "play.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helper.h"

#define COUNTER_CHAR 'O'
#define MIN_PILES 3
#define MAX_PILES 5
#define MIN_PILE_COUNTERS 1
#define MAX_PILE_COUNTERS 20

struct GameState {
    int num_piles;
    int *piles;
};

struct PlayerMove {
    int pile;
    int counters;
};

// Returns the total number of counters in-game
int init_game(struct GameState *restrict game)
{
    srand(time(NULL));

    game->num_piles = rand_int(MIN_PILES, MAX_PILES);
    game->piles = malloc(sizeof(int) * game->num_piles);

    // Initialize piles with counters
    int counters;
    int total = 0;
    for (int i = 0; i < game->num_piles; ++i) {
        counters = rand_int(MIN_PILE_COUNTERS, MAX_PILE_COUNTERS);
        game->piles[i] = counters;
        total += counters;
    }
    return total;
}

void display_piles(const struct GameState *const restrict game)
{
    for (int i = 0; i < game->num_piles; ++i) {
        printf("Pile %d: ", i + 1);
        for (int j = 0; j < game->piles[i]; ++j)
            putchar(COUNTER_CHAR);
        for (int j = game->piles[i]; j <= MAX_PILE_COUNTERS; ++j)
            putchar(' ');
        printf("%d\n", game->piles[i]);
    }
}

bool is_num_input(const char *const restrict input, int *const restrict num)
{
    int tmp = 0;
    int i;
    for (i = 0; input[i]; ++i) {
        if (isdigit(input[i])) {
            tmp *= 10;
            tmp += input[i] - '0';
        } else {
            return false;
        }
    }
    if (!i) // check for empty input
        return false;
    else
        *num = tmp;
    return true;
}

void get_move(const struct GameState *const restrict game,
    struct PlayerMove *const restrict move)
{
    char input[4096];
    bool input_num;
    bool input_valid = false;
    do {
        fputs("Which pile would you like to remove from? ", stdout);
        fgets(input, sizeof input, stdin);
        strip_newline(input);

        input_num = is_num_input(input, &move->pile);
        if (input_num) {
            if (!move->pile || move->pile > game->num_piles)
                puts("That pile does not exist. Try again.");
            else if (!game->piles[move->pile - 1])
                puts("You must select a non-empty pile. Try again.");
            else
                input_valid = true;
        } else {
            puts("That is not a valid number. Try again.");
        }
    } while (!input_valid);
    input_valid = false;
    do {
        fputs("How many counters would you like to remove? ", stdout);
        fgets(input, sizeof input, stdin);
        strip_newline(input);

        input_num = is_num_input(input, &move->counters);
        if (input_num) {
            if (!move->counters)
                puts("Please remove at least 1 counter. Try again.");
            else if (move->counters > game->piles[move->pile - 1])
                puts("There are not that many counters to remove. Try again.");
            else
                input_valid = true;
        } else {
            puts("That is not a valid number. Try again.");
        }
    } while (!input_valid);
}

void play(void)
{
    struct GameState game;
    int total_counters = init_game(&game);

    int curr_player = 1;
    struct PlayerMove move;
    while (total_counters > 0) {
        printf("Player %d's turn\n\n", curr_player);
        display_piles(&game);
        putchar('\n');

        get_move(&game, &move);
        game.piles[move.pile - 1] -= move.counters;
        total_counters -= move.counters;
        printf(
            "\nPlayer %d removed %d counters from pile %d.\n"
            "Counters: %d -> %d\n\n",
            curr_player, move.counters, move.pile,
            game.piles[move.pile - 1] + move.counters, game.piles[move.pile - 1]
        );
        curr_player = !(curr_player - 1) + 1;
    }
    printf("Congratulations Player %d, you won the game!", curr_player);
    free(game.piles);
}
