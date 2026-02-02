#include "locations.h"
#include "../evidence/evidence.h"
#include <string.h>

void init_locations(Location locations[]) {

    /* PM's Office */
    locations[LOC_PM_OFFICE].id = LOC_PM_OFFICE;
    strcpy(locations[LOC_PM_OFFICE].name, "Prime Minister's Office");
    locations[LOC_PM_OFFICE].visited = 0;
    locations[LOC_PM_OFFICE].times_visited = 0;
    locations[LOC_PM_OFFICE].time_cost = 2;

    /* Medical Wing */
    locations[LOC_MEDICAL_WING].id = LOC_MEDICAL_WING;
    strcpy(locations[LOC_MEDICAL_WING].name, "Medical Wing");
    locations[LOC_MEDICAL_WING].visited = 0;
    locations[LOC_MEDICAL_WING].times_visited = 0;
    locations[LOC_MEDICAL_WING].time_cost = 4;
    
    /* Intel Room */
    locations[LOC_INTEL_ROOM].id = LOC_INTEL_ROOM;
    strcpy(locations[LOC_INTEL_ROOM].name, "Intelligence Control Room");
    locations[LOC_INTEL_ROOM].visited = 0;
    locations[LOC_INTEL_ROOM].times_visited = 0;
    locations[LOC_INTEL_ROOM].time_cost = 3;
    
    /* Press Area */
    locations[LOC_PRESS_AREA].id = LOC_PRESS_AREA;
    strcpy(locations[LOC_PRESS_AREA].name, "Press Area");
    locations[LOC_PRESS_AREA].visited = 0;
    locations[LOC_PRESS_AREA].times_visited = 0;
    locations[LOC_PRESS_AREA].time_cost = 1;
    
    /* Interrogation Room */
    locations[LOC_INTERROGATION].id = LOC_INTERROGATION;
    strcpy(locations[LOC_INTERROGATION].name, "Interrogation Room");
    locations[LOC_INTERROGATION].visited = 0;
    locations[LOC_INTERROGATION].times_visited = 0;
    locations[LOC_INTERROGATION].time_cost = 2;
    
    /* Detective's Office */
    locations[LOC_DETECTIVE_OFFICE].id = LOC_DETECTIVE_OFFICE;
    strcpy(locations[LOC_DETECTIVE_OFFICE].name, "Detective's Office");
    locations[LOC_DETECTIVE_OFFICE].visited = 0;
    locations[LOC_DETECTIVE_OFFICE].times_visited = 0;
    locations[LOC_DETECTIVE_OFFICE].time_cost = 0;
}
