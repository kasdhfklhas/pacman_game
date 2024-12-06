#ifndef GHOSTS_H
#define GHOSTS_H

#include "stdbool.h"

#define NUM_GHOSTS 3
#define GHOST_SYMBOL "G"

#define GHOST_1_ROW 13
#define GHOST_1_COL 12
#define GHOST_2_ROW 13
#define GHOST_2_COL 13
#define GHOST_3_ROW 14
#define GHOST_3_COL 21

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"

typedef struct {
    int behavior;
    const char* ghost_color;
    const char* symbole;
    int ghost_position_coordinates[2];
    bool crossed_gate;
} Ghost;

#endif
