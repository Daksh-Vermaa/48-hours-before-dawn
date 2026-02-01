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
#define SAVE_FILE "detective_save.dat"

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

/* Suspect IDs */
typedef enum
{
    SUSPECT_HOME_MINISTER = 0,
    SUSPECT_NSA = 1,
    SUSPECT_PHYSICIAN = 2,
    SUSPECT_CHIEF_STAFF = 3
} SuspectID;

#endif