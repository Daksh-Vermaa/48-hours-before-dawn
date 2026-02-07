#include <string.h>

#include "suspects.h"
#include "../ui/ui.h"

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

const char* get_suspect_name(int suspect_id) {
    switch(suspect_id) {
        case SUSPECT_HOME_MINISTER: return "Arvind Kaul";
        case SUSPECT_NSA: return "Meera Iyer";
        case SUSPECT_PHYSICIAN: return "Dr. Raghav Sen";
        case SUSPECT_CHIEF_STAFF: return "Nalin Verma";
        default: return "Unknown";
    }
}

void update_suspect_trust(Suspect *suspect, int change) {
    suspect->trust += change;
    if (suspect->trust < 0) suspect->trust = 0;
    if (suspect->trust > 100) suspect->trust = 100;
}

int check_contradiction_available(GameState *state, int suspect_id) {
    switch(suspect_id) {
        case SUSPECT_HOME_MINISTER:
        return (state->evidence_flags & EV_RESHUFFLE_PLAN) != 0;
        case SUSPECT_NSA:
        return (state->evidence_flags & EV_CAMERA_GAP) != 0;
        case SUSPECT_PHYSICIAN:
        return (state->evidence_flags & EV_ENZYME_DATA) != 0;
        case SUSPECT_CHIEF_STAFF:
        return (state->evidence_flags & EV_MEETING_DELETION) != 0;
        default:
        return 0;
    }
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

        /* Case - 1 */
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
        
        /* Case - 2 */
        case SUSPECT_NSA:
            print_slowly("Meera Iyer studies you the way soldiers study terrain.", 800);
            print_slowly("\"Ask your questions, Detective.\"", 800);
            wait_for_space();
            
            if (state->evidence_flags & EV_CAMERA_GAP) {
                print_slowly("\nYou ask about the camera maintenance.", 600);
                print_slowly("She doesn't deny it.", 600);
                print_slowly("\"National security protocol. Some things don't need to be recorded.\"", 800);
                wait_for_space();
                print_slowly("\"Which things?\"", 600);
                print_slowly("She smiles faintly. \"The dangerous ones.\"", 800);
                suspect->known_contradictions |= (1 << 0);
            }
            break;

        /* Case - 3 */
        case SUSPECT_PHYSICIAN:
            print_slowly("Dr. Sen looks exhausted. Offended.", 800);
            print_slowly("\"I've managed his health for twelve years.\"", 800);
            wait_for_space();
            
            if (state->evidence_flags & EV_ENZYME_DATA) {
                print_slowly("\nYou confront him with the enzyme data.", 600);
                print_slowly("His shoulders sag.", 600);
                wait_for_space();
                print_slowly("\"I didn't kill him. I swear.\"", 800);
                print_slowly("\"But... the vial. Someone replaced it.\"", 800);
                print_slowly("\"I administered the injection. It was logged. Scheduled. Normal.\"", 800);
                wait_for_space();
                print_slowly("\"But the vial was different. I noticed... too late.\"", 800);
                state->evidence_flags |= EV_VIAL_REPLACEMENT;
                suspect->known_contradictions |= (1 << 0);
            }
            break;

        /* Case - 4 */
        case SUSPECT_CHIEF_STAFF:
            print_slowly("Nalin Verma hasn't slept in days.", 800);
            print_slowly("\"He trusted the people in this room.\"", 800);
            wait_for_space();
            
            if (state->evidence_flags & EV_RESHUFFLE_PLAN) {
                print_slowly("\nYou ask why the meeting was deleted from the schedule.", 600);
                print_slowly("He looks down.", 600);
                print_slowly("\"He asked me to. He wanted discretion.\"", 800);
                state->evidence_flags |= EV_MEETING_DELETION;
                suspect->known_contradictions |= (1 << 0);
            }
            break;
    }

    wait_for_space();
    deduct_time(state, 2);
}