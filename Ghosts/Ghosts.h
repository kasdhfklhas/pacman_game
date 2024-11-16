#ifndef GHOSTS_H
#define GHOSTS_H

#define NUM_GHOSTS 3
#define GHOST_SYMBOL "G"
#define BEHAVIOR_FLEE 0
#define BEHAVIOR_CATCH 1

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

typedef struct{
    int behavior;
    const char* ghost_color;
    const char* symbole;
    int positions[];
}Ghost;

#endif