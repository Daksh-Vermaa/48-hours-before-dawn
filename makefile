# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
LDFLAGS =

# Directories
SRC_DIR = crime_scene
OBJ_DIR = obj
BIN_DIR = .

# Target
TARGET = $(BIN_DIR)/crime_scene_

# Sources (relative to SRC_DIR)
SOURCES = \
	main.c \
	game.c \
	story/story.c \
	suspects/suspects.c \
	evidence/evidence.c \
	locations/locations.c \
	save/save.c \
	ui/ui.c \
	utils/utils.c

# Derived paths
SRC_FILES = $(addprefix $(SRC_DIR)/,$(SOURCES))
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default
all: $(TARGET)

# Link
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET) $(LDFLAGS)

# Compile (auto-create dirs)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Utilities
clean:
	rm -rf $(OBJ_DIR) $(TARGET) crime_scene_.dat

run: $(TARGET)
	./$(TARGET)

debug: CFLAGS += -g -DDEBUG
debug: clean all

.PHONY: all clean run debug
