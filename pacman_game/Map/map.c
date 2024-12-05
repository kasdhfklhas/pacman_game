#include "../Vars.h"
#include "Map.h"
#include <stdlib.h>
#include <stdio.h>

char rawMap[GRID_ROWS][GRID_COLS + 1] = {
    "#############################",
    "#############################",
    "## * * * * * ### * * * * * ##",
    "## ### ##### ### ##### ### ##",
    "##*###*##### ###*#####*###*##",
    "##* * * * * * * * * * * * ##",
    "## ### ## ######### ## ### ##",
    "##*### ##*#########*##*###*##",
    "##* * *## * * ## * ##* * *##",
    "###### ###### ## ##### ######",
    "######*###### ## ##### ######",
    "###### ## * * * * * * ######",
    "######*##*###---###*## ######",
    "###### ## ## ## ## ######",
    "######*##*## ## ##*######",
    "O ##*## ## ## O",
    "######*##*## ## ##*######",
    "###### ## ## ## ## ######",
    "######*##*#########*## ######",
    "###### ## * * * * * * ######",
    "######*###### ## ##### ######",
    "###### ###### ## ##### ######",
    "##* * *## * * ## * ##* * *##",
    "##*### ##*#########*##*### ##",
    "## ### ## ######### ## ### ##",
    "##* * * * * * * * * * * * ##",
    "##*###*##### ###*#####*###*##",
    "## ### ##### ### ##### ### ##",
    "## * * * * * ### * * * * * ##",
    "#############################",
    "#############################",
};

void initMap() {
    for (int y = 0; y < GRID_ROWS; y++) {
        for (int x = 0; x < GRID_COLS; x++) {
            grid.tiles[y][x] = rawMap[y][x];  // Copy each character from rawMap to grid.tiles
        }
        grid.tiles[y][GRID_COLS] = '\0';  // Null-terminate each row for easier printing
    }
}

void destroyMap() {
    // No need to free anything since memory is statically allocated
}

char getTile(int row, int col) {
    if (row < 0 || row >= GRID_ROWS || col < 0 || col >= GRID_COLS) {
        return '#';  // Return wall if out of bounds
    }
    return grid.tiles[row][col];
}
