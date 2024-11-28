#include "stdbool.h"
#include "Ghosts.h"
#include <Vars.h>


// Check if the position is valid for ghost movement
bool is_valid_move(int row, int col) {
    return getTile(row, col) != '#' && getTile(row, col) != 'G';
}

void ghost_movement() {
    for (int i = 0; i < NUM_GHOSTS; i++) {
        int current_row = ghost[i].ghost_position_coordinates[0];
        int current_col = ghost[i].ghost_position_coordinates[1];
        int target_row = current_row, target_col = current_col;

        switch (ghost[i].behavior) {
            case 0: // Chaser: Move towards Pac-Man
                if (pacman.pacman_position_coordinates[0] > current_row) target_row++;
                else if (pacman.pacman_position_coordinates[0] < current_row) target_row--;
                if (pacman.pacman_position_coordinates[1] > current_col) target_col++;
                else if (pacman.pacman_position_coordinates[1] < current_col) target_col--;
                break;

            case 1: // Ambusher: Predict Pac-Man's position
                if (pacman.direction == 'w') target_row -= 2;
                else if (pacman.direction == 's') target_row += 2;
                else if (pacman.direction == 'a') target_col -= 2;
                else if (pacman.direction == 'd') target_col += 2;
                break;

            case 2: // Random: Move in a random direction
                int random_direction = rand() % 4;
                if (random_direction == 0) target_row = current_row - 1; // Up
                else if (random_direction == 1) target_col = current_col + 1; // Right
                else if (random_direction == 2) target_row = current_row + 1; // Down
                else if (random_direction == 3) target_col = current_col - 1; // Left
                break;
        }

        // Validate move
        if (is_valid_move(target_row, target_col)) {
            ghost[i].ghost_position_coordinates[0] = target_row;
            ghost[i].ghost_position_coordinates[1] = target_col;
        }
    }
}
