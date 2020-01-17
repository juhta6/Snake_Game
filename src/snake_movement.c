#include "headers/game_header.h"

void snake_movement() {
	
	switch(key) {
		case 'w':
		case KEY_UP:
			if(direction != "down" && !paused)
				direction = "up";
			if(!started) started = true;
			break;
		case 'a':
		case KEY_LEFT:
			if(direction != "right" && !paused)
				direction = "left";
			if(!started) started = true;
			break;
		case 's':
		case KEY_DOWN:
			if(direction != "up" && !paused)
				direction = "down";
			if(!started) started = true;
			break;
		case 'd':
		case KEY_RIGHT:
			if(direction != "left" && !paused)
				direction = "right";
			if(!started) started = true;
			break;
		case 'p': 
			if(!paused && !gameOver) paused = true; else paused = false;
			break;
		case '\n':
			if(gameOver) end();
			break;
			
			
			
		//cheat keys
		case '+':
			if(length < MAX_LENGTH && started)
			length++;
			break;
		case '-':
			if(length > 0 && started)
			length--;
			break;
	}
	
	//prints the body that follows the head
	for(int i = length; i >= 1; i--) {
		wattron(game, COLOR_PAIR(3));
		wattron(game, A_DIM);
		mvwprintw(game, BODY_Y, BODY_X, "o");
		wattroff(game, A_DIM);
		wattroff(game, COLOR_PAIR(3));
		
		if(HEAD_Y == BODY_Y && HEAD_X == BODY_X)
		gameOver = true;
	
		
		if(!gameOver && !paused) {
			BODY_Y = snake_y[i-1];
			BODY_X = snake_x[i-1];
		}
			
		
	}
	
	wattron(game, COLOR_PAIR(3));
	wattron(game, A_BOLD);
	mvwprintw(game, HEAD_Y, HEAD_X, "O");
	wattroff(game, A_BOLD);
	wattroff(game, COLOR_PAIR(3));
	
	if(!gameOver && !paused) {
		if(direction == "up")
			HEAD_Y--;
		else if(direction == "left")
			HEAD_X--;
		else if(direction == "down")
			HEAD_Y++;
		else if(direction == "right")
			HEAD_X++;
	} else if(paused) {
		wattron(game, COLOR_PAIR(3));
		wattron(game, A_BLINK);
		wattron(game, A_STANDOUT);
		mvwprintw(game, 1, 1, "Paused!");
		wattroff(game, A_STANDOUT);
		wattroff(game, A_BLINK);
		wattroff(game, COLOR_PAIR(3));
	} else if(gameOver) {
		wattron(game, COLOR_PAIR(3));
		wattron(game, A_BLINK);
		wattron(game, A_STANDOUT);
		mvwprintw(game, 1, 1, "Game over!");
		mvwprintw(game, 2, 1, "Press ENTER to restart!");
		wattroff(game, A_STANDOUT);
		wattroff(game, A_BLINK);
		wattroff(game, COLOR_PAIR(3));
	}
	
	
	//boundaries
	if(HEAD_Y >= GAME_HEIGHT-1) {
		if(length < 40) HEAD_Y = 1;
		else gameOver = true;
	}
	if(HEAD_Y <= 0) {
		if(length < 40) HEAD_Y = GAME_HEIGHT-2;
		else gameOver = true;
	}
	if(HEAD_X >= GAME_WIDTH-1) {
		if(length < 40) HEAD_X = 1;
		else gameOver = true;
	}
	if(HEAD_X <= 0) {
		if(length < 40) HEAD_X = GAME_WIDTH-2;
		else gameOver = true;
	}
	
}