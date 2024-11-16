#ifndef PACMAN_H
#define PACMAN_H

#include <stdbool.h>
#define GRID_ROWS 32
#define GRID_COLS 29
#define PACMAN_SYMBOL "P"
#define LIVES 3
#define YELLOW  "\033[33m"

typedef struct {
    int grid_size[2];
    int pacman_position[2];
    int score;
    bool is_game_over;
    int lives;
    int grid[GRID_ROWS][GRID_COLS];
    int foods;
    const char* pacman_color;
    const char* symbole;
} Pacman;

#endif 