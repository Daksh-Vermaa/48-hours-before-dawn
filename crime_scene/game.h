#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

/* Game Constants */
#define NUM_SUSPECTS 4
#define NUM_LOCATIONS 6
#define MAX_EVIDENCE 32
#define SAVE_FILE "crime_scene_.dat" //Change save file name

/* Locations IDs */
typedef enum
{
    LOC_PM_OFFICE = 0,
    LOC_MEDICAL_WING = 1,
    LOC_INTEL_ROOM = 2,
    LOC_PRESS_AREA = 3,
    LOC_INTERROGATION = 4,
    LOC_DETECTIVE_OFFICE = 5
} LocationID;

/* Suspects IDs */
typedef enum
{
    SUSPECT_HOME_MINISTER = 0,
    SUSPECT_NSA = 1,
    SUSPECT_PHYSICIAN = 2,
    SUSPECT_CHIEF_STAFF = 3
} SuspectID;

/* Evidence Flags */
typedef enum
{
    EV_NOTEBOOK = (1 << 0),
    EV_TEA_CUP = (1 << 1),
    EV_ENZYME_DATA = (1 << 2),
    EV_CAMERA_GAP = (1 << 3),
    EV_RESHUFFLE_PLAN = (1 << 4),
    EV_VIAL_REPLACEMENT = (1 << 5),
    EV_KITCHEN_LOG = (1 << 6),
    EV_BIOMETRIC_LOG = (1 << 7),
    EV_MEETING_DELETION = (1 << 8),
    EV_INTEL_CLEARANCE = (1 << 9),
    EV_TOXIN_REPORT = (1 << 10),
    EV_INJECTION_LOG = (1 << 11)
} EvidenceFlag;

/* Story Nodes */
typedef enum 
{
    NODE_INTRO = 0,
    NODE_OPENING_SCENE,
    NODE_IMMEDIATE_CIRCLE,
    NODE_CRIME_SCENE,
    NODE_MEDICAL_WING,
    NODE_INTEL_ROOM,
    NODE_INTERROGATIONS,
    NODE_PHYSICIAN_BREAKS,
    NODE_MISSING_PIECE,
    NODE_FINAL_CONFRONTATION,
    NODE_TRUTH_ASSEMBLES,
    NODE_ACCUSATION,
    NODE_ENDING
} StoryNode;

/* Endings */
typedef enum 
{
    END_TRUE_RESOLUTION,
    END_PARTIAL_TRUTH,
    END_FALSE_ACCUSATION,
    END_TIMEOUT
} Ending;

/* Suspect Structure */
typedef struct 
{
    char name[50];
    int is_killer;
    int trust;
    unsigned int known_contradictions;
    int interrogated;
    int times_questioned;
} Suspect;

/* Evidence Structure */
typedef struct 
{
    int id;
    char name[100];
    char description[300];
    unsigned int unlocks;
    int discovered;
} Evidence;

/* Location Structure */
typedef struct 
{
    int id;
    char name[50];
    int visited;
    int times_visited;
    int time_cost;
} Location;

/* Game State */
typedef struct 
{
    int hours_remaining;
    unsigned int evidence_flags;
    unsigned int visited_locations;
    int suspect_trust[NUM_SUSPECTS];
    int current_story_node;
    int game_over;
    Ending ending_type;
    int accusation_made;
    int accused_suspect;
}GameState;

/* Functions Declartions */
void init_game_state(GameState *state);
void update_game_state(GameState *state);
int check_win_condition(GameState *state, int accused);
void deduct_time(GameState *state, int hours);

#endif /* GAME_H */