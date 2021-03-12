#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "play.h"

#define NIM_VERSION "1.1.0-alpha"

static void print_help(FILE *restrict stream)
{
    fputs(
        "Usage:\n"
        "    nim <command> [<args>]\n\n"
        "The parameter <command> can be one of the following:\n"
        "    help\t\tPrint this help message.\n"
        "    info\t\tPrint program information.\n"
        "    play [type]\t\tStart the game with the specified opponent type.\n"
        "    \t\t\t[type] can be 'comp' or 'human' for a computer or human\n"
        "    \t\t\topponent respectively.\n"
        "    rules\t\tPrints gameplay rules.\n",
        stream);
}

static void print_info(void)
{
    printf(
        "C Terminal Nim - Version %s\n"
        "Author: Eric Wan (ericw31415)\n"
        "Github page: https://github.com/ericw31415/c-terminal-nim\n",
        NIM_VERSION);
}

static void print_rules(void)
{
    puts(
        "How to play:\n\n"
        "C Terminal Nim plays just like normal Nim, so read no further if you\n"
        "have played it before.\n\n"
        "In Nim, there are several piles containing counters. On your turn, you\n"
        "select a pile and remove as many counters as you want from it, but you\n"
        "must remove at least 1. The winner of the game is the player who removes\n"
        "the last counter.\n\n"
        "Playing the game:\n\n"
        "Run 'nim play' and follow the prompts that appear in your terminal. Have\n"
        "fun!");
}

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        fputs("No command specified.\n", stderr);
        print_help(stderr);
        return EXIT_FAILURE;
    } else {
        if (!strcmp(argv[1], "help")) {
            print_help(stdout);
        } else if (!strcmp(argv[1], "info")) {
            print_info();
        } else if (!strcmp(argv[1], "play")) {
            if (argc <= 2) {
                fputs("Please specify an opponent type.\n", stderr);
                print_help(stderr);
                return EXIT_FAILURE;
            } else {
                if (!strcmp(argv[2], "comp")) {
                    play(COMPUTER);
                } else if (!strcmp(argv[2], "human")) {
                    play(HUMAN);
                } else {
                    fputs("Invalid opponent type specified.\n", stderr);
                    print_help(stderr);
                    return EXIT_FAILURE;
                }
            }
        } else if (!strcmp(argv[1], "rules")) {
            print_rules();
        } else {
            fputs("Invalid command specified.\n", stderr);
            print_help(stderr);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
