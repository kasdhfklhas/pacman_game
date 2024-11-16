#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "messages.h"
#include "map.h"

#define GRID_ROWS 20
#define GRID_COLS 20
#define LIVES 3
#define BEHAVIOR_FLEE 0
#define BEHAVIOR_CATCH 1




//ANSI ESCAPE Codes for Colors
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"



typedef struct {
    int grid_size[2];
    int pacman_position[2];
    int score;
    bool is_game_over;
    int lives;
    int grid[GRID_ROWS][GRID_COLS];
    int foods;
    const char* pacman_color;
} Pacman_Game;

Pacman_Game game;

typedef struct{
    int foods;
    int specialfoods;

}Foods;

typedef struct{
    int postion[];
    int behavior;
    const char* ghost_color;

}Ghost;

void initialize_pacman(Pacman_Game* game){ //struct initalisieren
    game->grid_size[0] = GRID_ROWS;
    game->grid_size[1] = GRID_COLS;
    game->pacman_position[0] = 0 + 1; //Zeile unterhalb der Wand;
    game->pacman_position[1] = GRID_COLS - 1 - 1; //Spalte neben der Wand
    game->score = 0;
    game->lives = LIVES;
    game->is_game_over = false;
    game->pacman_color = YELLOW;
  

}
void initialize_ghost(Ghost* ghost){ //struct initalisieren
    ghost->behavior = BEHAVIOR_CATCH;
    ghost->ghost_color = RED;

}

void initialize_foods(Foods* food){
    food->foods = 20;
}


void load_level() {
    // Level laden und initialisieren
}

void generate_map() {
    // Karte generieren
}

void print_map() {
    // Karte drucken
}

void touch_enemy() {
    if(game->lives == 0){
        gameOver(game);
    }else{game->lives = game->lives- 1;}
    
}

void collect_food(Foods* food) {
    if(food.foods == 0){
        gameEnd();
    }
}

void end_game() {
    // Das Spiel endet
}

void start_game() {
    initialize_pacman(&game);
    initialize_ghost(&ghost);
    initialize_foods(&food);

    //TODO: GAMEschleife hier einfügen
}

void move_pacman( char direction) {
    // Pacman bewegen
}

void teleport_pacman() {
    // Pacman an eine andere Position teleportieren
}

void ghost_movement() {
    // Bewegung der Geister
}

void check_collision() {
    // Kollision überprüfen
}

void update_map() {
    // Karte aktualisieren
}

void update_score() {
    // Punktestand aktualisieren
}

void display_status() {
    // Spielstatus anzeigen
}

void check_win_condition() {
    // Gewinnbedingung überprüfen
}

void pause_game() {
    // Spiel pausieren
}

void power_up_collected() {
    // Power-Up einsammeln
}

void gameEnd(){
    game.is_game_over = true;
    if(game.lives == 0){printf(GAME_OVER);}
    else if(game.foods == 0){printf(YOU_WON)};
    
    
}


int main() {
    start_game(&game);
    return 0;
}
