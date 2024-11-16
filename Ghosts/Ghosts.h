#ifndef GHOSTS_H
#define GHOSTS_H

#define NUM_GHOSTS 3

typedef struct{
    int positions[][];
    int behavior;
    const char* ghost_color;
    const char* symbole;

}Ghost;

#endif