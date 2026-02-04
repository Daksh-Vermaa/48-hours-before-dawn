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
    for (int i = 0; i < NUM_SUSPECTS; i++)
    {
        state->suspect_trust[i] = 50; /* Neutral trust */
    }
}

void update_game_state (GameState *state) {
    if (state -> hours_remaining <= 0)
    {
        state->game_over = 1;
        state->ending_type = END_TIMEOUT;
    }
}
