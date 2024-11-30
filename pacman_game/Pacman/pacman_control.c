#include "Pacman.h"
#include "../Vars.h"
#include "../Map/Map.h"


void move_pacman(char direction) {
    int next_row = pacman.pacman_position_coordinates[0];
    int next_col = pacman.pacman_position_coordinates[1];

    switch (direction) {
        case 'w':
            next_row--;
            break;
        case 'a':
            next_col--;
            break;
        case 's':
            next_row++;
            break;
        case 'd':
            next_col++;
            break;
        default:
            return;
    }

    // Move only if the next position is not a wall
    if (getTile(next_row, next_col) != '#') {
        pacman.pacman_position_coordinates[0] = next_row;
        pacman.pacman_position_coordinates[1] = next_col;
    }
}
