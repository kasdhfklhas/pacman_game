#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "messages.h"

#define GRID_ROWS 20
#define GRID_COLS 20
#define LIVES 3

//Definierte Textmessages
#define GAME_OVER "Game Over!\n"

typedef struct {
    int grid_size[2];
    int pacman_position[2];
    int score;
    bool is_game_over;
    int lives;
    int grid[GRID_ROWS][GRID_COLS];
    int foods;
} Pacman_Game;

void initialize_pacman(Pacman_Game* game){ //struct initalisieren
    game->grid_size[0] = GRID_ROWS;
    game->grid_size[1] = GRID_COLS;
    game->pacman_position[0] = 0 + 1; //Zeile unterhalb der Wand;
    game->pacman_position[1] = GRID_COLS - 1 - 1; //Spalte neben der Wand
    game->score = 0;
    game->lives = LIVES;
    game->is_game_over = false;
    //Todo: game->foods =

}


void load_level(PacmanGame* game) {
    // Level laden und initialisieren
}

void generate_map(PacmanGame* game) {
    // Karte generieren
}

void print_map(PacmanGame* game) {
    // Karte drucken
}

void touch_enemy(PacmanGame* game) {
    if(game->lives == 0){
        gameOver(game);
    }else{game->lives = game->lives- 1;}
    
}

void collect_dot(PacmanGame* game) {
    // Spieler sammelt einen Dot ein
}

void end_game(PacmanGame* game) {
    // Das Spiel endet
}

void start_game(PacmanGame* game) {
    // Spiel starten
}

void move_pacman(PacmanGame* game, char direction) {
    // Pacman bewegen
}

void teleport_pacman(PacmanGame* game) {
    // Pacman an eine andere Position teleportieren
}

void ghost_movement(PacmanGame* game) {
    // Bewegung der Geister
}

void check_collision(PacmanGame* game) {
    // Kollision überprüfen
}

void update_map(PacmanGame* game) {
    // Karte aktualisieren
}

void update_score(PacmanGame* game) {
    // Punktestand aktualisieren
}

void display_status(PacmanGame* game) {
    // Spielstatus anzeigen
}

void check_win_condition(PacmanGame* game) {
    // Gewinnbedingung überprüfen
}

void pause_game(PacmanGame* game) {
    // Spiel pausieren
}

void power_up_collected(PacmanGame* game) {
    // Power-Up einsammeln
}

void gameOver(PacmanGame* game){
    game->is_game_over = true;
    if(game.lives == 0){printf(GAME_OVER);}
    elseif(game.foods == 0){printf(YOU_WON)};
    
    
}


int main() {
    PacmanGame game;
    start_game(&game);
    return 0;
}
