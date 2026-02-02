#ifndef SUSPECTS_H
#define SUSPECTS_H
#include "../game.h"

/* Initialize all suspects */
void init_suspects(Suspect suspects[]);

/* Get suspect information */
const char *get_suspect_name(int suspect_id);
void print_suspect_info(Suspect *suspect);

/* Interrogation functions */
void interrogate_suspect(GameState *state, Suspect suspects[], int suspect_id);
void update_suspect_trust(Suspect *suspect, int change);

/* Check suspect contradictions */
int check_contradiction_available(GameState *state, int suspect_id);

#endif /* SUSPECTS_H */