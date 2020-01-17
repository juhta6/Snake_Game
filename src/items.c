#include "headers/game_header.h"

void spawnPoint() {
	wattron(game, COLOR_PAIR(1));
	wattron(game, A_BOLD);
	mvwprintw(game, point_y, point_x, "+");
	wattroff(game, A_BOLD);
	wattroff(game, COLOR_PAIR(1));
	
	for(int i = length; i >= 1; i--) {
		if(point_y == BODY_Y && point_x == BODY_X) {
			point_y = rand() % (GAME_HEIGHT - 2) + 1;
			point_x = rand() % (GAME_WIDTH - 2) + 1;
		}
	}
	
	if(HEAD_Y == point_y && HEAD_X == point_x) {
		point_y = rand() % (GAME_HEIGHT - 2) + 1;
		point_x = rand() % (GAME_WIDTH - 2) + 1;
		bomb_y = rand() % (GAME_HEIGHT - 2) + 1;
		bomb_x = rand() % (GAME_WIDTH - 2) + 1;
		if(length < MAX_LENGTH) {
			length++;
			sleeptime -= 1000;
		}
		points++;
		if(highscore <= points)
			highscore = points;
		
	}
}

void spawnBomb() {
	if(points > 10 ) {
		
		wattron(game, COLOR_PAIR(2));
		mvwprintw(game, bomb_y, bomb_x, "+");
		wattroff(game, COLOR_PAIR(2));
		
		for(int i = length; i >= 1; i--) {
			if((BODY_Y == bomb_y && BODY_X == bomb_x) || (point_y == bomb_y && point_x == bomb_x)) {
				bomb_y = rand() % (GAME_HEIGHT - 2) + 1;
				bomb_x = rand() % (GAME_WIDTH - 2) + 1;
			}
		}
		
		if(HEAD_Y == bomb_y && HEAD_X == bomb_x) {
			bomb_y = rand() % (GAME_HEIGHT - 2) + 1;
			bomb_x = rand() % (GAME_WIDTH - 2) + 1;
			if(length < MAX_LENGTH) {
				length++;
				sleeptime -= 1000;
			}
			points -= 2;
		}
	}
}