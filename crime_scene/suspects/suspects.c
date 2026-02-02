#include "suspects.h"
#include <string.h>

void init_suspects(Suspect suspects[]) {
    /* Home Affairs Minister - Arvind Kaul */
    strcpy(suspects[SUSPECT_HOME_MINISTER].name, "Arvind Kaul (Home Affairs Minister)");
    suspects[SUSPECT_HOME_MINISTER].is_killer = 1;
    suspects[SUSPECT_HOME_MINISTER].trust = 50;
    suspects[SUSPECT_HOME_MINISTER].known_contradictions = 0;
    suspects[SUSPECT_HOME_MINISTER].interrogated = 0;
    suspects[SUSPECT_HOME_MINISTER].times_questioned = 0;

    /* National Security Advisor - Meera Iyer */
    strcpy(suspects[SUSPECT_NSA].name, "Meera Iyer (National Security Advisor)");
    suspects[SUSPECT_NSA].is_killer = 1;
    suspects[SUSPECT_NSA].trust = 50;
    suspects[SUSPECT_NSA].known_contradictions = 0;
    suspects[SUSPECT_NSA].interrogated = 0;
    suspects[SUSPECT_NSA].times_questioned = 0;
    
    /* Personal Physician - Dr. Raghav Sen */
    strcpy(suspects[SUSPECT_PHYSICIAN].name, "Dr. Raghav Sen (Personal Physician)");
    suspects[SUSPECT_PHYSICIAN].is_killer = 0;
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