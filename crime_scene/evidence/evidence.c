#include "evidence.h"
#include <string.h>

void init_evidence(Evidence evidence_list[]) {
    int idx = 0;

    /* Notebook Clue */
    evidence_list[idx].id = idx;
    strcpy(evidence_list[idx].name, "Prime Minister's Notebook");
    strcpy(evidence_list[idx].description, "Contains: 'Dawn reshuffle. Some will not forgive me.'");
    evidence_list[idx].unlocks = EV_RESHUFFLE_PLAN;
    evidence_list[idx].discovered = 0;
    idx++;

    /* Tea Cup Clue */
    evidence_list[idx].id = idx;
    strcpy(evidence_list[idx].name, "Untouched Tea Cup");
    strcpy(evidence_list[idx].description, "Tea prepared 30 minutes before death. Never consumed.");
    evidence_list[idx].unlocks = 0;
    evidence_list[idx].discovered = 0;
    idx++;

    /* Enzyme Data Clue */
    evidence_list[idx].id = idx;
    strcpy(evidence_list[idx].name, "Unusual Enzyme Response");
    strcpy(evidence_list[idx].description, "Lab results show toxin mimicking cardiac arrest.");
    evidence_list[idx].unlocks = 0;
    evidence_list[idx].discovered = 0;
    idx++;

    /* Camera Gap Clue */
    evidence_list[idx].id = idx;
    strcpy(evidence_list[idx].name, "Camera Maintenance Log");
    strcpy(evidence_list[idx].description, "17-minute gap. Authorized by NSA Meera Iyer.");
    evidence_list[idx].unlocks = 0;
    evidence_list[idx].discovered = 0;
    idx++;

    /* Reshuffle Plan Clue */
    evidence_list[idx].id = idx;
    strcpy(evidence_list[idx].name, "Cabinet Reshuffle Document");
    strcpy(evidence_list[idx].description, "Final list. Home Minister would be removed.");
    evidence_list[idx].unlocks = 0;
    evidence_list[idx].discovered = 0;
    idx++;

    /* Vial Replacement */
    evidence_list[idx].id = idx;
    strcpy(evidence_list[idx].name, "Replaced Medication Vial");
    strcpy(evidence_list[idx].description, "Vitamin injection vial was tampered with.");
    evidence_list[idx].unlocks = 0;
    evidence_list[idx].discovered = 0;
    idx++;
}
