#include "Ghosts.h" // Include necessary headers
#include <stdbool.h>
#include "../Map/Map.h"


// Check if the position is valid
bool is_valid_move(int row, int col) {
    return grid.tiles[row][col] != '#' && grid.tiles[row][col] != 'G';
}





void ghost_movement() {
    for (int i = 0; i < NUM_GHOSTS; i++) {
        int current_row = ghost[i].ghost_position_coordinates[0];
        int current_col = ghost[i].ghost_position_coordinates[1];
        int target_row, target_col;

        switch (ghost[i].behavior) {
            case 0: // Red Ghost: Chaser
                target_row = pacman.pacman_position_coordinates[0];
                target_col = pacman.pacman_position_coordinates[1];
                break;

            case 1: // Green Ghost: Ambusher
                // Predict Pac-Man's position based on direction
                if (pacman.direction == 'w') {
                    target_row = pacman.pacman_position_coordinates[0] - 2;
                    target_col = pacman.pacman_position_coordinates[1];
                } else if (pacman.direction == 's') {
                    target_row = pacman.pacman_position_coordinates[0] + 2;
                    target_col = pacman.pacman_position_coordinates[1];
                } else if (pacman.direction == 'a') {
                    target_row = pacman.pacman_position_coordinates[0];
                    target_col = pacman.pacman_position_coordinates[1] - 2;
                } else if (pacman.direction == 'd') {
                    target_row = pacman.pacman_position_coordinates[0];
                    target_col = pacman.pacman_position_coordinates[1] + 2;
                } else {
                    target_row = pacman.pacman_position_coordinates[0];
                    target_col = pacman.pacman_position_coordinates[1];
                }
                break;

            case 2: // Blue Ghost: Random Walker
                target_row = current_row;
                target_col = current_col;

                // Choose a random direction (0 = up, 1 = right, 2 = down, 3 = left)
                int random_direction = rand() % 4;
                if (random_direction == 0 && map[current_row - 1][current_col] != '#') target_row = current_row - 1;
                if (random_direction == 1 && map[current_row][current_col + 1] != '#') target_col = current_col + 1;
                if (random_direction == 2 && map[current_row + 1][current_col] != '#') target_row = current_row + 1;
                if (random_direction == 3 && map[current_row][current_col - 1] != '#') target_col = current_col - 1;
                break;
        }

        // Move the ghost if the target position is valid
        if (map[target_row][target_col] != '#' && map[target_row][target_col] != 'G') {
            ghost[i].ghost_position_coordinates[0] = target_row;
            ghost[i].ghost_position_coordinates[1] = target_col;
        }
    }
}
