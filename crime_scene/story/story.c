#include "story.h"
#include "../ui/ui.h"
#include "../suspects/suspects.h"
#include <stdio.h>

void play_intro(void) {

    clear_screen();
    print_separator();
    printf("\n");
    printf("                    ╔═══════════════════════════════════════╗\n");
    printf("                    ║    48 HOURS BEFORE DAWN               ║\n");
    printf("                    ║    A Detective Mystery Adventure      ║\n");
    printf("                    ╚═══════════════════════════════════════╝\n");
    printf("\n");
    print_separator();
    printf("\n");
    pause_ms(1500);
    
    print_slowly("In the nation of Varuna, power moves in shadows.", 800);
    print_slowly("Tonight, the most powerful man in the country is dead.", 800);
    print_slowly("", 500);
    print_slowly("You are the detective.", 800);
    print_slowly("You have 48 hours before the media breaks the story.", 800);
    print_slowly("", 500);
    print_slowly("Four suspects. One truth. Zero second chances.", 1000);
    print_slowly("", 500);
    print_slowly("This is not about finding a killer.", 800);
    print_slowly("This is about understanding why power kills its own.", 1000);
    
    printf("\n");
    wait_for_space();
}

void play_opening_scene(GameState *state) {

    clear_screen();
    print_header("PRIME MINISTER'S RESIDENCE", state->hours_remaining);
    print_slowly("The rain has already decided it will not stop tonight.", 1000);
    print_slowly("", 500);
    print_slowly("It taps gently against the tall windows of the Prime Minister's residence,", 800);
    print_slowly("not loud enough to demand attention, not soft enough to ignore.", 800);
    wait_for_space();
    
    print_slowly("\nThe city outside sleeps uneasily, unaware that its spine has just cracked.", 1000);
    print_slowly("", 500);
    print_slowly("You stand at the threshold of the Prime Minister's private study.", 800);
    print_slowly("The door is closed. Locked from the inside.", 800);
    wait_for_space();
    
    print_slowly("\nA security officer unlocks it with shaking hands.", 800);
    print_slowly("", 800);
    print_slowly("The smell inside the room is familiar—", 600);
    print_slowly("polished wood, old paper, faint tea leaves.", 800);
    print_slowly("Power smells like this everywhere in the world.", 800);
    print_slowly("Old decisions. Quiet rooms.", 1000);
    wait_for_space();
    
    print_slowly("\nThe Prime Minister of Varuna sits in his chair,", 800);
    print_slowly("head slightly tilted, glasses still on his nose.", 800);
    print_slowly("His eyes are half-closed,", 600);
    print_slowly("as if he paused mid-thought and forgot to continue living.", 1200);
    wait_for_space();
    
    print_slowly("\nThe attending physician clears his throat.", 800);
    print_slowly("\"Cardiac arrest,\" he says. \"No sign of struggle.\"", 1000);
    print_slowly("", 800);
    print_slowly("You don't answer.", 800);
    print_slowly("", 500);
    print_slowly("Men this powerful do not simply stop.", 1200);
    wait_for_space();
}

void play_immediate_circle(GameState *state, Suspect suspects[]) {

    clear_screen();
    print_header("THE IMMEDIATE CIRCLE", state->hours_remaining);
    print_slowly("They arrive one by one, summoned quietly, urgently.", 1000);
    wait_for_space();
    
    /* Arvind Kaul */
    print_slowly("\n--- ARVIND KAUL - HOME AFFAIRS MINISTER ---", 800);
    print_slowly("", 300);
    print_slowly("He speaks first. Too quickly.", 800);
    print_slowly("\"This is a tragedy,\" he says. \"But stability must come first.\"", 1000);
    print_slowly("\"The country cannot afford speculation.\"", 800);
    wait_for_space();
    
    print_slowly("\nHis eyes flick to the body. Then away.", 800);
    print_slowly("He had a closed-door meeting with the Prime Minister that evening.", 800);
    print_slowly("Forty-three minutes. Official agenda: emergency legislation.", 1000);
    print_slowly("", 500);
    print_slowly("He says they argued.", 800);
    print_slowly("He does not say about what.", 1000);
    wait_for_space();
    
    /* Meera Iyer */
    print_slowly("\n--- MEERA IYER - NATIONAL SECURITY ADVISOR ---", 800);
    print_slowly("", 300);
    print_slowly("She says almost nothing.", 800);
    print_slowly("She studies the room the way soldiers study terrain.", 1000);
    print_slowly("Camera placements. Blind spots. Exits.", 800);
    wait_for_space();
    
    print_slowly("\nWhen you mention the media blackout, she nods once.", 800);
    print_slowly("\"As expected,\" she says.", 1000);
    print_slowly("", 500);
    print_slowly("You note that she did not ask why.", 1200);
    wait_for_space();
    
    /* Dr. Sen */
    print_slowly("\n--- DR. RAGHAV SEN - PERSONAL PHYSICIAN ---", 800);
    print_slowly("", 300);
    print_slowly("He looks exhausted. Offended.", 800);
    print_slowly("\"I've managed the Prime Minister's health for twelve years.\"", 1000);
    print_slowly("\"If something was wrong, I would have known.\"", 800);
    wait_for_space();
    
    print_slowly("\nHe already filed the report. Natural causes.", 800);
    print_slowly("He reminds you—politely—that revising it would cause panic.", 1200);
    wait_for_space();
    
    /* Nalin Verma */
    print_slowly("\n--- NALIN VERMA - CHIEF OF STAFF ---", 800);
    print_slowly("", 300);
    print_slowly("He hasn't slept.", 800);
    print_slowly("\"The Prime Minister dismissed everyone early,\" he says.", 1000);
    print_slowly("\"He wanted to think. He was under pressure.\"", 800);
    wait_for_space();
    
    print_slowly("\nHe hesitates before adding,", 600);
    print_slowly("\"He trusted the people in this room.\"", 1200);
    wait_for_space();
    
    print_slowly("\n\nYou are alone again with the body.", 800);
    print_slowly("And the clock.", 1000);
    wait_for_space();
    
    deduct_time(state, 2);
}

void play_final_accusation(GameState *state, Suspect suspects[]) {

    clear_screen();
    print_header("FINAL ACCUSATION", state->hours_remaining);
    print_slowly("The evidence board stares back at you.", 1000);
    print_slowly("Names. Timelines. Contradictions. Lies.", 800);
    print_slowly("", 800);
    print_slowly("The media waits.", 600);
    print_slowly("The dawn approaches.", 800);
    print_slowly("", 800);
    print_slowly("You must choose.", 1200);
    wait_for_space();
    
    printf("\n");
    print_separator();
    printf("WHO DO YOU ACCUSE?\n");
    print_separator();
    printf("\n");
    
    printf("  1. Arvind Kaul (Home Affairs Minister)\n");
    printf("  2. Meera Iyer (National Security Advisor)\n");
    printf("  3. Dr. Raghav Sen (Personal Physician)\n");
    printf("  4. Nalin Verma (Chief of Staff)\n");
    printf("\n");
    
    int choice = get_choice(4);
    state->accused_suspect = choice - 1;
    state->accusation_made = 1;
    
    printf("\n");
    print_slowly("You make your decision.", 1000);
    print_slowly("There is no going back.", 1000);
    wait_for_space();
    
    check_win_condition(state, state->accused_suspect);
}

void play_ending(GameState *state, Suspect suspects[]) {

    clear_screen();
    print_separator();
    switch(state->ending_type) {
        case END_TRUE_RESOLUTION:
            printf("\n              ENDING: TRUE RESOLUTION\n");
            print_separator();
            printf("\n");
            
            print_slowly("The arrest happens at dawn.", 1000);
            print_slowly("", 500);
            print_slowly("Meera Iyer does not resist.", 800);
            print_slowly("She stands calmly as the charges are read.", 800);
            print_slowly("Conspiracy to murder. Abuse of state power. Treason.", 1200);
            wait_for_space();
            
            print_slowly("\nArvind Kaul tries to flee.", 800);
            print_slowly("He makes it to the airport before they stop him.", 1000);
            print_slowly("", 500);
            print_slowly("Dr. Sen is placed under protective custody.", 800);
            print_slowly("An unwitting accomplice. A victim of access.", 1000);
            wait_for_space();
            
            print_slowly("\nThe press conference happens before noon.", 800);
            print_slowly("The nation wakes up screaming.", 1000);
            print_slowly("But awake.", 1200);
            print_slowly("", 800);
            print_slowly("The Prime Minister planned to remove corrupt ministers.", 800);
            print_slowly("They removed him first.", 1000);
            wait_for_space();
            
            print_slowly("\nPower does not fear enemies.", 1000);
            print_slowly("It fears daylight.", 1000);
            print_slowly("", 500);
            print_slowly("And daylight, once invited in,", 800);
            print_slowly("never leaves quietly.", 1500);
            break;
            
        case END_PARTIAL_TRUTH:
            printf("\n              ENDING: PARTIAL TRUTH\n");
            print_separator();
            printf("\n");
            
            print_slowly("One conspirator is arrested.", 1000);
            print_slowly("The other escapes through legal loopholes.", 1000);
            print_slowly("Classified intelligence. National security exemptions.", 1200);
            wait_for_space();
            
            print_slowly("\nThe official story is sanitized.", 800);
            print_slowly("\"Internal investigation. Appropriate actions taken.\"", 1000);
            print_slowly("", 500);
            print_slowly("Stability is preserved.", 800);
            print_slowly("Justice is... incomplete.", 1200);
            wait_for_space();
            
            print_slowly("\nYou solved part of the puzzle.", 800);
            print_slowly("But power protects its own.", 1000);
            print_slowly("Always has. Always will.", 1200);
            break;
            
        case END_FALSE_ACCUSATION:
            printf("\n              ENDING: FALSE ACCUSATION\n");
            print_separator();
            printf("\n");
            
            print_slowly("You accused the wrong person.", 1000);
            print_slowly("", 800);
            print_slowly("The media erupts.", 800);
            print_slowly("Questions of competence. Political interference. Cover-up.", 1200);
            wait_for_space();
            
            print_slowly("\nThe real killers remain free.", 800);
            print_slowly("Your career ends quietly.", 1000);
            print_slowly("", 500);
            print_slowly("In six months, no one remembers your name.", 1200);
            print_slowly("But the Prime Minister stays dead.", 1000);
            print_slowly("And the truth stays buried.", 1500);
            break;
            
        case END_TIMEOUT:
            printf("\n              ENDING: MEDIA LEAK\n");
            print_separator();
            printf("\n");
            
            print_slowly("Time runs out.", 1000);
            print_slowly("", 800);
            print_slowly("The press breaks the story without answers.", 1000);
            print_slowly("Speculation becomes fact. Rumors become truth.", 1200);
            wait_for_space();
            
            print_slowly("\nChaos.", 800);
            print_slowly("", 500);
            print_slowly("The government falls within a week.", 1000);
            print_slowly("Riots in three cities.", 800);
            print_slowly("Emergency powers invoked.", 1200);
            wait_for_space();
            
            print_slowly("\nYou had 48 hours.", 800);
            print_slowly("You needed more.", 1000);
            print_slowly("", 500);
            print_slowly("The Prime Minister deserved better.", 1500);
            break;
    }

    printf("\n");
    print_separator();
    printf("\n              GAME OVER\n");
    print_separator();
    printf("\n");

    wait_for_space();
}