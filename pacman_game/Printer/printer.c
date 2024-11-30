#include <Vars.h>

char prepareFrame() {
  char * frame[GRID_COLS][GRID_ROWS];

  for (int y = 0; y < GRID_COLS; y++) {
    for (int x = 0; x < GRID_ROWS; x++) {
      char str[] = getTile(x,y);
      frame[y][x] = str;
    }
  }

 
  // add the various "dynamic" elements to the frame -> pacman, ghosts

  int x = pacman.pacman_position_coordinates[0];
  int y = pacman.pacman_position_coordinates[1];

  frame[y][x] = PACMAN_STR; 
}

void renderFrame(char * frame) {
  for (int y = 0; y < GRID_COLS; y++) {
    for (int x = 0; x < GRID_ROWS; x++) {
      printf("%s", frame[y][&x]);
    }
    printf("\n");
  }
}