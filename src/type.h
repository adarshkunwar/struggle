#ifndef TYPE_H
#define TYPE_H

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 10
#define GROUND_HEIGHT 8
#define AVAILABLE_HEIGHT SCREEN_HEIGHT - GROUND_HEIGHT + 1

/* ── ANSI ── */
#define RESET "\033[0m"
#define DIM "\033[2m"
#define FAINT "\033[38;5;240m"
#define GREY "\033[38;5;245m"
#define WHITE "\033[37m"
#define BLOOD "\033[38;5;124m"
#define EMBER "\033[38;5;130m"
#define PALE "\033[38;5;250m"
#define BOLD "\033[1m"
#define GREEN "\033[38;5;40m"
#define BLUE "\033[38;5;33m"

typedef struct { int x; int y; } Position;

#endif // !TYPE_H
