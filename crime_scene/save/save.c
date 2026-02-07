#include <stdio.h>
#include <string.h>

#include "save.h"

typedef struct {
    GameState game_state;
    Location locations[NUM_LOCATIONS];
    Suspect suspects[NUM_SUSPECTS];
} SaveData;

int save_game(GameState *state, Location locations[], Suspect suspects[]) {
    FILE *file = fopen(SAVE_FILE, "wb");

    if (file == NULL) {
        return 0;
    }

    SaveData save_data;
    memcpy(&save_data.game_state, state, sizeof(GameState));
    memcpy(save_data.locations, locations, sizeof(Location) * NUM_LOCATIONS);
    memcpy(save_data.suspects, suspects, sizeof(Suspect) * NUM_SUSPECTS);
    
    size_t written = fwrite(&save_data, sizeof(SaveData), 1, file);
    fclose(file);
    
    return written == 1;
}

int load_game(GameState *state, Location locations[], Suspect suspects[]) {
    FILE *file = fopen(SAVE_FILE, "rb");

    if (file == NULL) {
        return 0;
    }

    SaveData save_data;
    size_t read = fread(&save_data, sizeof(SaveData), 1, file);
    fclose(file);
    
    if (read != 1) {
        return 0;
    }
    
    memcpy(state, &save_data.game_state, sizeof(GameState));
    memcpy(locations, save_data.locations, sizeof(Location) * NUM_LOCATIONS);
    memcpy(suspects, save_data.suspects, sizeof(Suspect) * NUM_SUSPECTS);
    
    return 1;
}

int save_exists(void) {
    FILE *file = fopen(SAVE_FILE, "rb");

    if (file == NULL) {
        return 0;
    }
    fclose(file);
    return 1;
}