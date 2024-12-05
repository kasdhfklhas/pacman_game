#include "../Vars.h"
#include "stdio.h"

void prepareFrame(char frame[GRID_ROWS][GRID_COLS+1]) {
    for (int y = 0; y < GRID_COLS; y++) {
        for (int x = 0; x < GRID_ROWS; x++) {
            frame[y][x] = getTile(x, y);
        }
    }
    int x = pacman.pacman_position_coordinates[0];
    int y = pacman.pacman_position_coordinates[1];
    frame[y][x] = PACMAN_STR[0]; 
}

void renderFrame(char frame[GRID_ROWS][GRID_COLS+1]) {
    for (int y = 0; y < GRID_COLS; y++) {
        for (int x = 0; x < GRID_ROWS; x++) {
            printf("%c", frame[y][x]);
        }
        printf("\n");
    }
}
