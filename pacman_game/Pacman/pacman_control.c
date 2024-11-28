#include "Pacman.h"
#include <Vars.h>


void move_pacman(char drection) {
    int next_row = pacman.pacman_position_coordinates[0];
    int next_col = pacman.pacman_position_coordinates[1];

    char direction = drection;

    if(getTile(next_row, next_col) != '#' && check_collision()){
        switch(direction){
            case 'w':
                next_row --;
                break;
            case 'a':
                next_col --;
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
        
        pacman.pacman_position_coordinates[0] = next_row;
        pacman.pacman_position_coordinates[1] = next_col;

        }
       
        
    }

