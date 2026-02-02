#ifndef LOCATIONS_H
#define LOCATIONS_H

#include "../game.h"

/* Initialize locations */
void init_locations(Location locations[]);

/* Visit location */
void visit_location(GameState *state, Location locations[], Suspect suspects[], int location_id);

/* Get location name */
const char *get_location_name(int location_id);

#endif /* LOCATIONS_H */