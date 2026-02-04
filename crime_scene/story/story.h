#ifndef STORY_H
#define STORY_H

#include "../game.h"

/* Story progression */
void play_intro(void);
void play_opening_scene(GameState *state);
void play_immediate_circle(GameState *state, Suspect suspects[]);
void play_final_accusation(GameState *state, Suspect suspects[]);
void play_ending(GameState *state, Suspect suspects[]);

#endif /* STORY_H */