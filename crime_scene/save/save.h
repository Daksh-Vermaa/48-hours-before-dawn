#ifndef SAVE_H
#define SAVE_H

#include "../game.h"

/* Save game state */
int save_game(GameState *state, Location locations[], Suspect suspects[]);

/* Load game state */
int load_game(GameState *state, Location locations[], Suspect suspects[]);

/* Check if save file exists */
int save_exists(void);

#endif /* SAVE_H */