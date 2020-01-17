#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define MAIN_HEIGHT 5
#define MAIN_WIDTH 12

#define RULES_HEIGHT 15
#define RULES_WIDTH 62

#define DIFFICULTY_HEIGHT 6
#define DIFFICULTY_WIDTH 20

#define EASY 1
#define NORMAL 2
#define HARD 3
#define RETURN 4

#define POINTER ACS_BULLET

int main_menu(void);
int start(int difficulty);
int difficulty_menu(void);
int rules_menu(void);

WINDOW *menu;
int item_number;
int key;
