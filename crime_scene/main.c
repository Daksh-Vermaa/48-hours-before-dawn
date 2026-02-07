#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "ui/ui.h"
#include "story/story.h"
#include "suspects/suspects.h"
#include "evidence/evidence.h"
#include "locations/locations.h"

void display_main_menu(GameState *state, Location locations[], Suspect suspects[], Evidence evidence_list[]);
void new_game(GameState *state, Location locations[], Suspect suspects[], Evidence evidence_list[]);
void continue_game(GameState *state, Location locations[], Suspect suspects[], Evidence evidence_list[]);
int main(void) {
    GameState state;
    Location locations[NUM_LOCATIONS];
    Suspect suspects[NUM_SUSPECTS];
    Evidence evidence_list[MAX_EVIDENCE];

    /* Show intro */
    play_intro();

    /* Main menu */
    clear_screen();
    print_separator();
    printf("\n              MAIN MENU\n");
    print_separator();
    printf("\n");
    
    if (save_exists()) {
        printf("  1. New Game\n");
        printf("  2. Continue\n");
        printf("  3. Exit\n");
        
        int choice = get_choice(3);
        
        if (choice == 1) {
            new_game(&state, locations, suspects, evidence_list);
        } 
        else if (choice == 2) {
            if (load_game(&state, locations, suspects)) {
                init_evidence(evidence_list);
                printf("\nGame loaded successfully!\n");
                pause_ms(1000);
                continue_game(&state, locations, suspects, evidence_list);
            }
            else {
                printf("\nFailed to load save file.\n");
                pause_ms(1000);
                new_game(&state, locations, suspects, evidence_list);
            }
        }
        else {
            return 0;
        }
    }
    else {
        printf("  1. New Game\n");
        printf("  2. Exit\n");
        
        int choice = get_choice(2);
        
        if (choice == 1) {
            new_game(&state, locations, suspects, evidence_list);
        }
        else {
            return 0;
        }
    }
    
    return 0;
}