#include "suspects.h"
#include "../ui/ui.h"
#include <string.h>

void init_suspects(Suspect suspects[]) {
    /* Home Affairs Minister - Arvind Kaul */
    strcpy(suspects[SUSPECT_HOME_MINISTER].name, "Arvind Kaul (Home Affairs Minister)");
    suspects[SUSPECT_HOME_MINISTER].is_killer = 1; /* Part of conspiracy */
    suspects[SUSPECT_HOME_MINISTER].trust = 50;
    suspects[SUSPECT_HOME_MINISTER].known_contradictions = 0;
    suspects[SUSPECT_HOME_MINISTER].interrogated = 0;
    suspects[SUSPECT_HOME_MINISTER].times_questioned = 0;

    /* National Security Advisor - Meera Iyer */
    strcpy(suspects[SUSPECT_NSA].name, "Meera Iyer (National Security Advisor)");
    suspects[SUSPECT_NSA].is_killer = 1; /* Mastermind */
    suspects[SUSPECT_NSA].trust = 50;
    suspects[SUSPECT_NSA].known_contradictions = 0;
    suspects[SUSPECT_NSA].interrogated = 0;
    suspects[SUSPECT_NSA].times_questioned = 0;
    
    /* Personal Physician - Dr. Raghav Sen */
    strcpy(suspects[SUSPECT_PHYSICIAN].name, "Dr. Raghav Sen (Personal Physician)");
    suspects[SUSPECT_PHYSICIAN].is_killer = 0; /* Unwitting accomplice */
    suspects[SUSPECT_PHYSICIAN].trust = 50;
    suspects[SUSPECT_PHYSICIAN].known_contradictions = 0;
    suspects[SUSPECT_PHYSICIAN].interrogated = 0;
    suspects[SUSPECT_PHYSICIAN].times_questioned = 0;
    
    /* Chief of Staff - Nalin Verma */
    strcpy(suspects[SUSPECT_CHIEF_STAFF].name, "Nalin Verma (Chief of Staff)");
    suspects[SUSPECT_CHIEF_STAFF].is_killer = 0;
    suspects[SUSPECT_CHIEF_STAFF].trust = 50;
    suspects[SUSPECT_CHIEF_STAFF].known_contradictions = 0;
    suspects[SUSPECT_CHIEF_STAFF].interrogated = 0;
    suspects[SUSPECT_CHIEF_STAFF].times_questioned = 0;
}

void interrogate_suspect(GameState *state, Suspect suspects[], int suspect_id) {
    
    Suspect *suspect = &suspects[suspect_id];
    suspect->interrogated = 1;
    suspect->times_questioned++;
    clear_screen();
    print_header("INTERROGATION ROOM", state->hours_remaining);
    
    printf("You sit across from %s.\n\n", get_suspect_name(suspect_id));
    wait_for_space();

    switch(suspect_id) {
        case SUSPECT_HOME_MINISTER:
            print_slowly("Arvind Kaul speaks first. Too quickly.", 800);
            print_slowly("\"This is a tragedy. But stability must come first.\"", 800);
            wait_for_space();
            
            if (state->evidence_flags & EV_RESHUFFLE_PLAN) {
                print_slowly("\nYou mention the reshuffle plan.", 600);
                print_slowly("His face tightens.", 600);
                print_slowly("\"Yes. He was going to remove me. After everything I did for this country.\"", 800);
                wait_for_space();
                suspect->known_contradictions |= (1 << 0);
            }
            
            print_slowly("\n\"Did you threaten him?\"", 600);
            print_slowly("\"No. I argued. That's not a crime.\"", 800);
            break;
}