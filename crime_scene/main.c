#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "ui/ui.h"
#include "story/story.h"
#include "suspects/suspects.h"
#include "evidence/evidence.h"
#include "locations/locations.h"
#include "save/save.h"

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

void new_game(GameState *state, Location locations[], Suspect suspects[], Evidence evidence_list[]) {

    /* Initialize game */
    init_game_state(state);
    init_locations(locations);
    init_suspects(suspects);
    init_evidence(evidence_list);
    /* Play opening scenes */
    play_opening_scene(state);
    play_immediate_circle(state, suspects);

    /* Enter main game loop */
    continue_game(state, locations, suspects, evidence_list);
}

void continue_game(GameState *state, Location locations[], Suspect suspects[], Evidence evidence_list[]) {
    while (!state->game_over && !state->accusation_made) {
        display_main_menu(state, locations, suspects, evidence_list);

        if (state->hours_remaining <= 0) {
            state->game_over = 1;
            state->ending_type = END_TIMEOUT;
            break;
        }
    }
    
    /* Final accusation if not timeout */
    if (!state->game_over && state->hours_remaining > 0) {
        play_final_accusation(state, suspects);
    }
    
    /* Show ending */
    play_ending(state, suspects);
}

void display_main_menu(GameState *state, Location locations[], Suspect suspects[], Evidence evidence_list[]) {
    clear_screen();
    print_header("DETECTIVE'S COMMAND CENTER", state->hours_remaining);
    printf("What do you want to do?\n\n");

    printf("LOCATIONS:\n");
    printf("  1. Visit Prime Minister's Office\n");
    printf("  2. Visit Medical Wing\n");
    printf("  3. Visit Intelligence Control Room\n");
    printf("  4. Visit Press Area\n");
    printf("  5. Visit Interrogation Room\n");
    printf("\n");

    printf("INVESTIGATION:\n");
    printf("  6. Review Evidence Board\n");
    printf("  7. Make Final Accusation\n");
    printf("\n");

    printf("SYSTEM:\n");
    printf("  8. Save Game\n");
    printf("  9. Exit Game\n");
    printf("\n");

    int choice = get_choice(9);

    switch(choice) {
        case 1:
            visit_location(state, locations, suspects, LOC_PM_OFFICE);
            break;

        case 2:
            visit_location(state, locations, suspects, LOC_MEDICAL_WING);
            break;

        case 3:
            visit_location(state, locations, suspects, LOC_INTEL_ROOM);
            break;

        case 4:
            visit_location(state, locations, suspects, LOC_PRESS_AREA);
            break;

        case 5:
            visit_location(state, locations, suspects, LOC_INTERROGATION);
            break;

        case 6:
            display_evidence_board(state, evidence_list);
            break;

        case 7:
            /* Confirm accusation */
            clear_screen();
            printf("\nAre you sure you want to make your final accusation?\n");
            printf("This cannot be undone.\n\n");
            printf("  1. Yes, I'm ready\n");
            printf("  2. No, continue investigation\n");

            int confirm = get_choice(2);
            if (confirm == 1) {
                state->accusation_made = 1;
            }
            break;

        case 8:
            if (save_game(state, locations, suspects)) {
                printf("\nGame saved successfully!\n");
            } else {
                printf("\nFailed to save game.\n");
            }
            pause_ms(1500);
            break;

        case 9:
            printf("\nAre you sure you want to exit?\n");
            printf("  1. Yes\n");
            printf("  2. No\n");

            int exit_confirm = get_choice(2);
            if (exit_confirm == 1) {
                state->game_over = 1;
                state->ending_type = END_TIMEOUT;
            }
            break;
    }
}