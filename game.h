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

#endif