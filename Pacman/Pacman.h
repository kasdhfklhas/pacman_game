#ifndef PACMAN_H
#define PACMAN_H

#define PACMAN_SYMBOL "P"
#define LIVES 3
#define YELLOW  "\033[33m"

//PACMAN Spawn
#define PACMAN_SPAWNPOINT_ROW 2
#define PACMAN_SPAWNPOINT_COL 26

typedef struct {
    int pacman_position_coordinates[2];
    int score;
    int lives;
    int foods;
    bool powerUp;
    const char* pacman_color;
    const char* symbole;
} Pacman;

#endif 