#define _DEFAULT_SOURCE

#include "ui.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

void clear_screen(void) {
    printf("\033[2J\033[H");
    fflush(stdout);
}

void print_header(const char *location, int hours_left) {
    print_separator();
    printf("  %s — %d HOURS REMAINING\n", location, hours_left);
    print_separator();
    printf("\n");
}

void print_separator(void) {
    printf("════════════════════════════════════════════════════════════════════════════════\n");
}

void pause_ms(int milliseconds) {
    usleep(milliseconds * 1000);
}

void print_slowly(const char *text, int delay_ms) {
    printf("%s\n", text);
    fflush(stdout);
    pause_ms(delay_ms);
}

void print_line(const char *text) {
    printf("%s\n", text);
    fflush(stdout);
}

void print_typewriter(const char *text, int char_delay_ms) {
    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout);
        if (char_delay_ms > 0) {
            pause_ms(char_delay_ms);
        }
    }
    printf("\n");
    fflush(stdout);
}

char get_single_char(void) {
    struct termios old_tio, new_tio;
    char c;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    
    c = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    return c;
}

void wait_for_space(void) {
    printf("\n[Press SPACE to continue...]\n");
    fflush(stdout);
    char c;
    do {
        c = get_single_char();
    } 
    while (c != ' ');
}

int get_choice(int max_options) {
    int choice;
    char buffer[256];
    while (1) {
        printf("\nYour choice (1-%d): ", max_options);
        fflush(stdout);
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            continue;
        }
        
        if (sscanf(buffer, "%d", &choice) == 1) {
            if (choice >= 1 && choice <= max_options) {
                return choice;
            }
        }
        
        printf("Invalid choice. Please enter a number between 1 and %d.\n", max_options);
    }
}