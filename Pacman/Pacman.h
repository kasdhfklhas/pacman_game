#ifndef PACMAN_H
#define PACMAN_H

#include <stdbool.h>
#define GRID_ROWS 32
#define GRID_COLS 29

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