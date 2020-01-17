#include "headers/game_header.h"

int start(int difficulty) {
	delwin(game);
	
	switch(difficulty) {
		case EASY:
			height = 35;
			width = 70;
			break;
		case NORMAL:
			height = 25;
			width = 50;
			break;
		case HARD:
			height = 15;
			width = 30;
			break;
	}
	
	game = newwin(GAME_HEIGHT, GAME_WIDTH, 3, 0);
	keypad(game, TRUE);
	nodelay(game, TRUE);
	
	wbkgd(game, COLOR_PAIR(3));
	
	HEAD_Y = rand() % (GAME_HEIGHT - 2) + 1;
	HEAD_X = rand() % (GAME_WIDTH - 2) + 1;
	
	point_y = rand() % (GAME_HEIGHT - 2) + 1;
	point_x = rand() % (GAME_WIDTH - 2) + 1;
	
	bomb_y = rand() % (GAME_HEIGHT - 2) + 1;
	bomb_x = rand() % (GAME_WIDTH - 2) + 1;
	
	sleeptime = 100000;
	paused = false;
	
	while(key = wgetch(game)) {
		
		clear();
		
		if(key == 27) {
			end();
			keypad(game, FALSE);
			delwin(game);
			return 0;
		}
		
		
		mvprintw(0, 1, "Use WASD or arrows to change direction");
		mvprintw(1, 1, "Press P to pause and ESC to quit");
		
		wclear(game);
		bounds();
		snake_movement();
		spawnPoint();
		spawnBomb();
		stats();
		wrefresh(game);
		usleep(sleeptime);
		wresize(game, GAME_HEIGHT, GAME_WIDTH);
		bkgd(COLOR_PAIR(4));
		refresh();
		
	}
}

void bounds() {
	wattron(game, A_BOLD);
	if(length < 40) {
		wattron(game, COLOR_PAIR(1));
		box(game, 0, 0);
		wattroff(game, COLOR_PAIR(1));
	} else {
		wattron(game, COLOR_PAIR(2));
		box(game, 0, 0);
		wattroff(game, COLOR_PAIR(2));
		

		
	}
	
	wattroff(game, A_BOLD);
}

void stats() {
	if(length >= 40) {
		wattron(game, COLOR_PAIR(2));
		wattron(game, A_BLINK);
		wattron(game, A_STANDOUT);
		mvwprintw(game, GAME_HEIGHT-1, 1, "HITTING A WALL RESULTS IN GAME OVER");
		wattroff(game, A_STANDOUT);
		wattroff(game, A_BLINK);
		wattroff(game, COLOR_PAIR(2));
	}
	mvprintw(2, 1, "points: %d", points);
	mvprintw(2, 13, "length: %d", length);
	mvprintw(2, 25, "highscore: %d", highscore);
	
}

void end() {
	points = 0;
	length = 0;
	gameOver = false;
	paused = false;
	started = false;
	direction = "";
	
	for(int i = length; i >= 1; i--) {
		BODY_Y = 0;
		BODY_X = 0;
	}
	
	HEAD_Y = rand() % (GAME_HEIGHT - 2) + 1;
	HEAD_X = rand() % (GAME_WIDTH - 2) + 1;
	point_y = rand() % (GAME_HEIGHT - 2) + 1;
	point_x = rand() % (GAME_WIDTH - 2) + 1;
	bomb_y = rand() % (GAME_HEIGHT - 2) + 1;
	bomb_x = rand() % (GAME_WIDTH - 2) + 1;
	
	sleeptime = 100000;
}
