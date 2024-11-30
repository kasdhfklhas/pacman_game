#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Messages/messages.h"
#include "stdbool.h"
#include "Map/Map.h"
#include "Printer/Printer.h"

#include "Pacman/Pacman.h"
#include "Ghosts/Ghosts.h"

#include <termios.h> // für Input eingabe

#include "Map/map.c"
#include "Pacman/pacman_control.c"
#include "Ghosts/ghost_control.c"
#include "Vars.h"

/*

Sleep( 100/ 30 ); 
-> Sött öppe tue füre gameloop als game speed, hani usm grosse wiite internet

*/


//Global Variable
Pacman pacman;
Map grid;
Ghost ghost[NUM_GHOSTS];
bool game_running;



void set_raw_mode(bool enable) { //used for keyinput without the use of pressing Enter
    static struct termios oldt, newt;
    if (enable) {
        // Get current terminal attributes
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;

        // Disable canonical mode and echo
        newt.c_lflag &= ~(ICANON | ECHO);

        // Apply the changes
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        // Restore old terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}


void initialize_pacman(){ //struct initalisieren
    pacman.pacman_position_coordinates[0] = PACMAN_SPAWNPOINT_ROW;
    pacman.pacman_position_coordinates[1] = PACMAN_SPAWNPOINT_COL;
    pacman.score = 0;
    pacman.lives = LIVES;
    pacman.pacman_color = YELLOW;
    pacman.symbole = PACMAN_SYMBOL;
  
}
void initialize_ghost(){ //struct initalisieren
    int position_coordinates[NUM_GHOSTS][2] = {
        {GHOST_1_ROW,GHOST_1_COL},
        {GHOST_2_ROW, GHOST_2_COL},
        {GHOST_3_ROW,GHOST_3_COL}
    };

    for(int i = 0; i < NUM_GHOSTS; i++){
        ghost[i].ghost_position_coordinates[0] = position_coordinates[i][0];
        ghost[i].ghost_position_coordinates[1] = position_coordinates[i][1];

        if(i == 0){
            ghost[i].ghost_color = RED;
            ghost[i].behavior = 0; // Chaser
        } else if (i == 1){
            ghost[i].ghost_color = GREEN;
            ghost[i].behavior = 1; // Ambusher
        } else {
            ghost[i].ghost_color = BLUE;
            ghost[i].behavior = 2; // Random Walker
        }

        ghost[i].symbole = GHOST_SYMBOL;
    }
}    


void draw_game() {
    printf("Score: %d\t Lives: %d\n", pacman.score, pacman.lives);
    
    for (int row = 0; row < GRID_ROWS; ++row) {
        for (int col = 0; col < GRID_COLS; ++col) {
            bool entity_drawn = false;
            if (pacman.pacman_position_coordinates[0] == row && pacman.pacman_position_coordinates[1] == col) {
                printf("%s%s\033[0m", pacman.pacman_color, pacman.symbole);
                entity_drawn = true;
            }
            for (int i = 0; i < NUM_GHOSTS; ++i) {
                if (ghost[i].ghost_position_coordinates[0] == row && ghost[i].ghost_position_coordinates[1] == col) {
                    printf("%s%s\033[0m", ghost[i].ghost_color, ghost[i].symbole);
                    entity_drawn = true;
                }
            }
            if (!entity_drawn) {
                printf("%c", grid.tiles[row][col]);
            }
        }
        printf("\n");
    }
}

    

void gameEnd(){
 
    if(pacman.lives == 0){
        game_running = false;
        printf("%s",GAME_OVER);
        }
    else if(pacman.foods == 0){
        game_running = false;
        printf("%s",YOU_WON);
        }
    
    
}

void collect_food() {
    int row = pacman.pacman_position_coordinates[0];
    int col = pacman.pacman_position_coordinates[1];
    if (grid.tiles[row][col] == '*') {
        pacman.score += 10;
        pacman.foods -= 1;
        grid.tiles[row][col] = ' ';
    }
}


bool check_collision() {
    int row = pacman.pacman_position_coordinates[0];
    int col = pacman.pacman_position_coordinates[1];

     for (int i = 0; i < NUM_GHOSTS; i++){
        if(row == ghost[i].ghost_position_coordinates[0] && col == ghost[i].ghost_position_coordinates[1]){
            return true;
        }
    }
    return false;
}

void touch_enemy() {
  if (check_collision()) {
        pacman.lives -= 1;
        if (pacman.lives <= 0) {
            gameEnd();
        }
        // Reset pacman to spawn point after touching a ghost
        pacman.pacman_position_coordinates[0] = PACMAN_SPAWNPOINT_ROW;
        pacman.pacman_position_coordinates[1] = PACMAN_SPAWNPOINT_COL;
    }
}


void exitGame() {
    game_running = false;
    
}

void start_game() {
    initialize_pacman();
    initialize_ghost();
    initMap();

    game_running = true;
    set_raw_mode(true);

    while(game_running){
        printf(CONTROL_MESSAGE);

        char input = getchar();
        move_pacman(input);

        char frame = prepareFrame();
        usleep(100000); //langsamerer Loop
        renderFrame(frame);
    }
    set_raw_mode(false);
       
}



void teleport_pacman() {
    //aktuelle Position abrufen
    int current_row = pacman.pacman_position_coordinates[0];
    int current_col = pacman.pacman_position_coordinates[1];

    // Fixe Teleportationspunkte auf der Karte abrufen
    int teleport_point_1[2] = TELEPORT_COORDINATES_1;
    int teleport_point_2[2] = TELEPORT_COORDINATES_2;

    // Prüfen ob Pacman auf dem teleportationspunkt ist.
    if (current_row == teleport_point_1[0] && current_col == teleport_point_1[1]) {
        // Teleportieren im Fall1
        pacman.pacman_position_coordinates[0] = teleport_point_2[0];
        pacman.pacman_position_coordinates[1] = teleport_point_2[1];
    } else if (current_row == teleport_point_2[0] && current_col == teleport_point_2[1]) {
        // Teleportieren im Fall2
        pacman.pacman_position_coordinates[0] = teleport_point_1[0];
        pacman.pacman_position_coordinates[1] = teleport_point_1[1];
    }
}

void inputRead(char input) {
    switch (input) {
        case 'w':
        case 'a':
        case 's': 
        case 'd':
            move_pacman(input);
            teleport_pacman();
            break;
        case 'q': 
            exitGame();
            break;
        default:
            break;
    }
}

void start_game() {
    initialize_pacman();
    initialize_ghost();

    game_running = true;
    set_raw_mode(true);

    while(game_running){
        draw_game();
        printf(CONTROL_MESSAGE);

        char input = getchar();
        inputRead(input);
        ghost_movement();
        collect_food();
        touch_enemy();
        
        usleep(100000); //langsamerer Loop
        system("clear");

    }
    set_raw_mode(false);
    destroyMap();
       
}


void update_map() {
    // Karte aktualisieren
}

void update_score() {
    pacman.score += 1;
}

void display_status() {
    printf(pacman.score);
}


int main() {
    srand(time(NULL)); // For random ghost movement
    start_game();
    return 0;
}
