#include "game.h"
#include "suspects/suspects.h"
#include "evidence/evidence.h"

void init_game_state(GameState *state) {
    state->hours_remaining = 48;
    state->evidence_flags = 0;
    state->visited_locations = 0;
    state->current_story_node = NODE_INTRO;
    state->game_over = 0;
    state->accusation_made = 0;
    state->accused_suspect = -1;
    for (int i = 0; i < NUM_SUSPECTS; i++) {
        state->suspect_trust[i] = 50; /* Neutral trust */
    }
}

void update_game_state(GameState *state) {
    if (state -> hours_remaining <= 0) {
        state->game_over = 1;
        state->ending_type = END_TIMEOUT;
    }
}

void deduct_time(GameState *state, int hours) {
    state->hours_remaining -= hours;
    if (state->hours_remaining < 0) {
        state->hours_remaining = 0;
    }
    update_game_state(state);
}

int check_win_condition(GameState *state, int accused) {
    /* Required evidence for true resolution */
    unsigned int required_evidence = EV_ENZYME_DATA | EV_VIAL_REPLACEMENT |
    EV_CAMERA_GAP | EV_INTEL_CLEARANCE;
    /* Check if Home Minister and NSA are both implicated (conspiracy) */
    int has_required_evidence = (state->evidence_flags & required_evidence) == required_evidence;

    /* The true killer is the NSA (Meera Iyer) as mastermind
    But the conspiracy involves Home Minister too */

    if (accused == SUSPECT_NSA && has_required_evidence) {
        state->ending_type = END_TRUE_RESOLUTION;
        return 1;
    } 
    else if ((accused == SUSPECT_HOME_MINISTER || accused == SUSPECT_NSA) && 
    (state->evidence_flags & (EV_ENZYME_DATA | EV_VIAL_REPLACEMENT))) {
        state->ending_type = END_PARTIAL_TRUTH;
        return 1;
    } 
    else {
        state->ending_type = END_FALSE_ACCUSATION;
        return 0;
    }
}