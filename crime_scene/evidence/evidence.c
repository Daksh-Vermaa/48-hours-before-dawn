#include "evidence.h"
#include "../ui/ui.h"
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

void collect_evidence(GameState *state, unsigned int evidence_flag) {
    if ((state->evidence_flags & evidence_flag) == 0) {
        state->evidence_flags |= evidence_flag;
        printf("\n[NEW EVIDENCE COLLECTED]\n");
    }
}

int has_evidence(GameState *state, unsigned int evidence_flag) {
    return (state->evidence_flags & evidence_flag) != 0;
}

const char* get_evidence_name(unsigned int flag) {
    switch(flag) {
        case EV_NOTEBOOK: return "PM's Notebook";
        case EV_TEA_CUP: return "Tea Cup";
        case EV_ENZYME_DATA: return "Enzyme Data";
        case EV_CAMERA_GAP: return "Camera Gap";
        case EV_RESHUFFLE_PLAN: return "Reshuffle Plan";
        case EV_VIAL_REPLACEMENT: return "Vial Replacement";
        case EV_KITCHEN_LOG: return "Kitchen Log";
        case EV_BIOMETRIC_LOG: return "Biometric Log";
        case EV_MEETING_DELETION: return "Meeting Deletion";
        case EV_INTEL_CLEARANCE: return "Intel Clearance";
        case EV_TOXIN_REPORT: return "Toxin Report";
        case EV_INJECTION_LOG: return "Injection Log";
        default: return "Unknown Evidence";
    }
}

void display_evidence_board(GameState *state, Evidence evidence_list[]) {
    clear_screen();
    print_header("EVIDENCE BOARD", state->hours_remaining);
    printf("Collected Evidence:\n\n");
    
    int count = 0;
    unsigned int flags[] = {
        EV_NOTEBOOK, EV_TEA_CUP, EV_ENZYME_DATA, EV_CAMERA_GAP,
        EV_RESHUFFLE_PLAN, EV_VIAL_REPLACEMENT, EV_KITCHEN_LOG,
        EV_BIOMETRIC_LOG, EV_MEETING_DELETION, EV_INTEL_CLEARANCE,
        EV_TOXIN_REPORT, EV_INJECTION_LOG 
    };

    for (int i = 0; i < 12; i++) {
        if (has_evidence(state, flags[i])) {
            printf("  [%d] %s\n", ++count, get_evidence_name(flags[i]));
        }
    }

    if (count == 0) {
        printf("  No evidence collected yet.\n");
    }
    
    printf("\n");
    wait_for_space();
}