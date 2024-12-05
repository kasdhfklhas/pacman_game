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
#include <termios.h> // for input without pressing Enter
#include "Vars.h"

// Global Variable
Pacman pacman;
Map grid;
Ghost ghost[NUM_GHOSTS];
bool game_running;

void set_raw_mode(bool enable);
void initialize_pacman();
void initialize_ghost();
void draw_game();
void gameEnd();
void collect_food();
bool check_collision();
void touch_enemy();
void exitGame();
void start_game();
void teleport_pacman();
void inputRead(char input);
void destroyMap();
void move_pacman(char direction);
void ghost_movement();

void set_raw_mode(bool enable) { // used for keyinput without pressing Enter
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

void initialize_pacman() { // Struct initialization
    pacman.pacman_position_coordinates[0] = PACMAN_SPAWNPOINT_ROW;
    pacman.pacman_position_coordinates[1] = PACMAN_SPAWNPOINT_COL;
    pacman.score = 0;
    pacman.lives = LIVES;
    pacman.pacman_color = YELLOW;
    pacman.symbole = PACMAN_SYMBOL;
}

void initialize_ghost() { // Struct initialization
    int position_coordinates[NUM_GHOSTS][2] = {
        {GHOST_1_ROW, GHOST_1_COL},
        {GHOST_2_ROW, GHOST_2_COL},
        {GHOST_3_ROW, GHOST_3_COL}
    };

    for (int i = 0; i < NUM_GHOSTS; i++) {
        ghost[i].ghost_position_coordinates[0] = position_coordinates[i][0];
        ghost[i].ghost_position_coordinates[1] = position_coordinates[i][1];

        if (i == 0) {
            ghost[i].ghost_color = RED;
            ghost[i].behavior = 0; // Chaser
        } else if (i == 1) {
            ghost[i].ghost_color = GREEN;
            ghost[i].behavior = 2; // Random Walker
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

void gameEnd() {
    if (pacman.lives == 0) {
        game_running = false;
        printf("%s", GAME_OVER);
    } else if (pacman.foods == 0) {
        game_running = false;
        printf("%s", YOU_WON);
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

    for (int i = 0; i < NUM_GHOSTS; i++) {
        if (row == ghost[i].ghost_position_coordinates[0] && col == ghost[i].ghost_position_coordinates[1]) {
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

void teleport_pacman() {
    // Get current position
    int current_row = pacman.pacman_position_coordinates[0];
    int current_col = pacman.pacman_position_coordinates[1];

    // Fetch fixed teleport points on the map
    int teleport_point_1[2] = TELEPORT_COORDINATES_1;
    int teleport_point_2[2] = TELEPORT_COORDINATES_2;

    // Check if Pacman is on the teleportation point
    if (current_row == teleport_point_1[0] && current_col == teleport_point_1[1]) {
        // Teleport in case 1
        pacman.pacman_position_coordinates[0] = teleport_point_2[0];
        pacman.pacman_position_coordinates[1] = teleport_point_2[1];
    } else if (current_row == teleport_point_2[0] && current_col == teleport_point_2[1]) {
        // Teleport in case 2
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
    printf("test123");
    initialize_pacman();
    printf("testx");
    initialize_ghost();
    printf("test");
    initMap();
    printf("test");

    game_running = true;
    set_raw_mode(true);

    while (game_running) {
        draw_game();
        printf(CONTROL_MESSAGE);
        char input = getchar();
        inputRead(input);
        ghost_movement();
        collect_food();
        touch_enemy();
        usleep(100000); // Slower loop
        system("clear");
    }
    set_raw_mode(false);
    destroyMap();
}

int main() {
    srand(time(NULL)); // For random ghost movement
    start_game();
    return 0;
}