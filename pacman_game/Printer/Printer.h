#ifndef PRINTER_H
#define PRINTER_H
#include "../Map/Map.h"

void prepareFrame(char frame[GRID_ROWS][GRID_COLS+1]);
void renderFrame(char frame[GRID_ROWS][GRID_COLS+1]);

#endif
