#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#include "menu_header.h"

#define EASY 1
#define NORMAL 2
#define HARD 3

#define GAME_HEIGHT height
#define GAME_WIDTH width

#define _XOPEN_SOURCE 500

#define HEAD_Y snake_y[0]
#define HEAD_X snake_x[0]

#define BODY_Y snake_y[i]
#define BODY_X snake_x[i]

#define MAX_LENGTH 100

void bounds();
void snake_movement();
void spawnPoint();
void spawnBomb();
void stats();
void end();


int COLOR_GREY;

WINDOW *game;
int height, width;
int snake_y[MAX_LENGTH], snake_x[MAX_LENGTH];
int point_y, point_x;
int bomb_y, bomb_x;
int points, highscore;
int length;
int sleeptime;
int key;
char *direction;
bool gameOver, paused, started;