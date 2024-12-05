#include "Ghosts.h"
#include "../Vars.h"
#include "../Pacman/Pacman.h"
#include "stdlib.h"
#include "../Map/Map.h"

Ghost ghost[NUM_GHOSTS];
Pacman pacman;

void ghost_movement() {
    for (int i = 0; i < NUM_GHOSTS; i++) {
        int next_row = ghost[i].ghost_position_coordinates[0];
        int next_col = ghost[i].ghost_position_coordinates[1];

        switch (ghost[i].behavior) {
            case 0: // Chaser, move towards pacman
                if (pacman.pacman_position_coordinates[0] > next_row) next_row++;
                else if (pacman.pacman_position_coordinates[0] < next_row) next_row--;
                if (pacman.pacman_position_coordinates[1] > next_col) next_col++;
                else if (pacman.pacman_position_coordinates[1] < next_col) next_col--;
                break;
            case 2: // Random Walker, move randomly
                switch (rand() % 4) {
                    case 0: next_row++; break;
                    case 1: next_row--; break;
                    case 2: next_col++; break;
                    case 3: next_col--; break;
                }
                break;
            default:
                break;
        }

        if (getTile(next_row, next_col) != '#') {
            ghost[i].ghost_position_coordinates[0] = next_row;
            ghost[i].ghost_position_coordinates[1] = next_col;
        }
    }
}
