#ifndef PACMAN_H
#define PACMAN_H

#define PACMAN_SYMBOL "P"
#define LIVES 3
#define YELLOW  "\033[33m"


typedef struct {
    int pacman_position[2];
    int score;
    int lives;
    int foods;
    const char* pacman_color;
    const char* symbole;
} Pacman;

#endif 