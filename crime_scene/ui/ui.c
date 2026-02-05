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
