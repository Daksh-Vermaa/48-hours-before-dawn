#include "locations.h"
#include "../ui/ui.h"
#include "../evidence/evidence.h"
#include "../suspects/suspects.h"
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

const char* get_location_name(int location_id) {
    switch(location_id) {
        case LOC_PM_OFFICE: return "Prime Minister's Office";
        case LOC_MEDICAL_WING: return "Medical Wing";
        case LOC_INTEL_ROOM: return "Intelligence Control Room";
        case LOC_PRESS_AREA: return "Press Area";
        case LOC_INTERROGATION: return "Interrogation Room";
        case LOC_DETECTIVE_OFFICE: return "Detective's Office";
        default: return "Unknown Location";
    }
}

void visit_location(GameState *state, Location locations[], Suspect suspects[], int location_id) {
    Location *loc = &locations[location_id];
    loc->visited = 1;
    loc->times_visited++;
    state->visited_locations |= (1 << location_id);
    clear_screen();
    print_header(loc->name, state->hours_remaining);
    
    switch(location_id) {
        case LOC_PM_OFFICE:
            print_slowly("You return to the Prime Minister's study.", 800);
            print_slowly("The smell of power lingers. Polished wood. Old paper. Faint tea leaves.", 800);
            wait_for_space();
            
            if (loc->times_visited == 1) {
                print_slowly("\nOn the desk:", 600);
                print_slowly("  - A cup of tea, untouched", 600);
                print_slowly("  - A leather-bound notebook", 600);
                print_slowly("  - A pen uncapped", 600);
                wait_for_space();
                
                print_slowly("\nYou examine the notebook carefully.", 800);
                print_slowly("One line catches your attention:", 800);
                print_slowly("", 400);
                print_slowly("  'Dawn reshuffle. Some will not forgive me.'", 1000);
                wait_for_space();
                
                collect_evidence(state, EV_NOTEBOOK);
                collect_evidence(state, EV_RESHUFFLE_PLAN);
                collect_evidence(state, EV_TEA_CUP);
            } else {
                print_slowly("\nNothing new here. The room has already told you its secrets.", 800);
            }
            break;
        
        case LOC_MEDICAL_WING:
            print_slowly("The hospital smells like disinfectant and guilt.", 800);
            wait_for_space();
            
            if (loc->times_visited == 1) {
                print_slowly("\nYou order a secondary autopsy.", 800);
                print_slowly("Dr. Sen stiffens. \"This is unnecessary.\"", 800);
                print_slowly("You insist.", 800);
                wait_for_space();
                
                print_slowly("\nHours pass...", 1000);
                wait_for_space();
                
                print_slowly("\nA junior lab technician approaches quietly.", 800);
                print_slowly("\"There's something unusual,\" she whispers.", 800);
                print_slowly("\"An enzyme response inconsistent with natural cardiac failure.\"", 1000);
                wait_for_space();
                
                print_slowly("\nNot proof. But not nothing.", 800);
                collect_evidence(state, EV_ENZYME_DATA);
                collect_evidence(state, EV_TOXIN_REPORT);
            } else {
                print_slowly("\nThe lab is processing your requests. The toxin data confirms your suspicions.", 800);
            }
            break;
            
        
    }

    wait_for_space();
    deduct_time(state, loc->time_cost);
}