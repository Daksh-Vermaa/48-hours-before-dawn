#ifndef UI_H
#define UI_H

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

/* UI Functions */
void clear_screen(void);
void print_header(const char *location, int hours_left);
void print_slowly(const char *text, int delay_ms);
void print_line(const char *text);
void wait_for_space(void);
int get_choice(int max_options);
void print_separator(void);
void pause_ms(int milliseconds);
char get_single_char(void);
void print_typewriter(const char *text, int char_delay_ms);

#endif /* UI_H */