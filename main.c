#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Messages/messages.h"
#include "Map/map.h"
#include "stdbool.h"
#include "Pacman/Pacman.h"
#include "Ghosts/Ghosts.h"
#include "Ghosts/Spawnpositions.h"

#define GRID_ROWS 32
#define GRID_COLS 29
#define LIVES 3
#define BEHAVIOR_FLEE 0
#define BEHAVIOR_CATCH 1
#define GHOST_SYMBOLE "G"
#define PACMAN_SYMBOLE "P"


#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"



Pacman pacman;
Ghost ghost[NUM_GHOSTS];



void initialize_pacman(){ //struct initalisieren
    pacman.grid_size[0] = GRID_ROWS;
    pacman.grid_size[1] = GRID_COLS;
    pacman.pacman_position[0] = 0 + 1; //Zeile unterhalb der Wand;
    pacman.pacman_position[1] = GRID_COLS - 1 - 1; //Spalte neben der Wand
    pacman.score = 0;
    pacman.lives = LIVES;
    pacman.is_game_over = false;
    pacman.pacman_color = YELLOW;
    pacman.symbole = PACMAN_SYMBOLE;
  

}
void initialize_ghost(){ //struct initalisieren
    int ghost_position[NUM_GHOSTS][2]{
        {GHOST_1_ROW,GHOST_1_COL},
        {GHOST_2_ROW, GHOST_2_COL},
        {GHOST_3_ROW,GHOST_3_COL}
        };

    for(int i = 0; i < NUM_GHOSTS; i++){
        ghost[i].positions[0] = ghost_position[i][0];
        ghost[i].positions[1] = ghost_position[i][1];
        
        ghost[i].behavior = BEHAVIOR_CATCH;

        if(i == 0){
            ghost[i].ghost_color = RED;
        }else if (i == 1){
            ghost[i].ghost_color = GREEN;
        }else {
            ghost[i].ghost_color = BLUE;  
        }

        ghost[i].symbole = GHOST_SYMBOLE;
        
        }

    }


void print_map() {
    // Karte drucken
}
void gameEnd(){
    pacman.is_game_over = true;
    if(pacman.lives == 0){printf("%s",GAME_OVER);}
    else if(pacman.foods == 0){printf("%s",YOU_WON);}
    
    
}
void touch_enemy() {
    if(pacman.lives == 0){
        gameEnd();
    }else{pacman.lives = pacman.lives- 1;}
    
}

void collect_food() {
    
}

void exitGame() {
    // Das Spiel endet
}

void start_game() {
    initialize_pacman();
    initialize_ghost();
    
    //TODO: GAMEschleife hier einfügen
}

void move_pacman(char direction) {
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


void pause_game() {
    // Spiel pausieren
}

void power_up_collected() {
    // Power-Up einsammeln
}


int main() {
    start_game();
    return 0;
}
