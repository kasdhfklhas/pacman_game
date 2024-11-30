#ifndef MAP_H
#define MAP_H

#define GRID_ROWS 32
#define GRID_COLS 29

#define TELEPORT_COORDINATES_1 {15,0}
#define TELEPORT_COORDINATES_2  {15,28}
#define FOOD_COORDINATES \
    {2, 3}, {2, 5}, {2, 7}, {2, 9}, {2, 11}, {2, 13}, {2, 19}, {2, 21}, {2, 23}, {2, 25}, {2, 27}, \
    {4, 2}, {4, 6}, {4, 10}, {4, 14}, {4, 18}, {4, 22}, {4, 26}, {4, 30}, \
    {5, 3}, {5, 8}, {5, 18}, {5, 28}, \
    {7, 2}, {7, 6}, {7, 11}, {7, 14}, {7, 18}, {7, 23}, {7, 30} \

#define FOOD_AMOUNT 31
#define POWERUP_COORDINATES //TODO

typedef struct {
  char **tiles;
} Map;



char* rawMap[GRID_ROWS][GRID_COLS+1];



void initMap();
char getTile(int x, int y);



#endif
