#ifndef EVIDENCE_H
#define EVIDENCE_H
#include "../game.h"

/* Initialize Evidences */
void init_evidence(Evidence evidence_list[]);

/* Evidence Collection */
void collect_evidence(GameState *state, unsigned int evidence_flag);
int has_evidence(GameState *state, unsigned int evidence_flag);

/* Display Evidence */
void display_evidence_board(GameState *state, Evidence evidence_list[]);
const char *get_evidence_name(unsigned int flag);

#endif /* EVIDENCE_H */