#include "headers/menu_header.h"

int main_menu(void) {
	delwin(menu);
	menu = newwin(MAIN_HEIGHT, MAIN_WIDTH, 0, 0);
	keypad(menu, TRUE);
	nodelay(menu, TRUE);
	item_number = 1;
	while(1) {
		clear();
		wclear(menu);
		
		box(menu, 0, 0);
		mvwprintw(menu, 0, 1, "SNAKE GAME");
		mvwprintw(menu, 1, 3, "START");
		mvwprintw(menu, 2, 3, "RULES");
		mvwprintw(menu, 3, 3, "QUIT");
		
		key = wgetch(menu);
		if((key == 'w' || key == KEY_UP) && item_number > 1) item_number--;
		if((key == 's' || key == KEY_DOWN) && item_number < 3) item_number++;
		if(key == 27) return 0;
		
		mvwaddch(menu, item_number, 1, POINTER);
		
		switch(item_number) {
			case 1:
				wattron(menu, A_BLINK);
				mvwprintw(menu, 1, 3, "START");
				wattroff(menu, A_BLINK);
				
				if(key == '\n') difficulty_menu();
				
				break;
			case 2:
				wattron(menu, A_BLINK);
				mvwprintw(menu, 2, 3, "RULES");
				wattroff(menu, A_BLINK);
				
				if(key == '\n') rules_menu();
				
				break;
			case 3:
				wattron(menu, A_BLINK);
				mvwprintw(menu, 3, 3, "QUIT");
				wattroff(menu, A_BLINK);
				
				if(key == '\n') return 0;
		}
		
		wrefresh(menu);
		usleep(100000);
		refresh();
		
		wresize(menu, MAIN_HEIGHT, MAIN_WIDTH);
		
	}
}

int difficulty_menu() {
	delwin(menu);
	menu = newwin(DIFFICULTY_HEIGHT, DIFFICULTY_WIDTH, 0, 0);
	keypad(menu, TRUE);
	nodelay(menu, TRUE);
	item_number = 1;
	while(1) {
		clear();
		wclear(menu);
		
		box(menu, 0, 0);
		mvwprintw(menu, 0, 1, "SELECT DIFFICULTY");
		mvwprintw(menu, 1, 3, "EASY");
		mvwprintw(menu, 2, 3, "NORMAL");
		mvwprintw(menu, 3, 3, "HARD");
		mvwprintw(menu, 4, 3, "RETURN");
		
		key = wgetch(menu);
		if((key == 'w' || key == KEY_UP) && item_number > 1) item_number--;
		if((key == 's' || key == KEY_DOWN) && item_number < 4) item_number++;
		if(key == 27) return 0;
		
		mvwaddch(menu, item_number, 1, POINTER);
		
		switch(item_number) {
			case EASY:
				wattron(menu, A_BLINK);
				mvwprintw(menu, 1, 3, "EASY");
				wattroff(menu, A_BLINK);
				
				mvprintw(1, 21, "height: 35 width: 70");
				
				break;
			case NORMAL:
				wattron(menu, A_BLINK);
				mvwprintw(menu, 2, 3, "NORMAL");
				wattroff(menu, A_BLINK);
				
				mvprintw(2, 21, "height: 25 width: 50");
				
				break;
			case HARD:
				wattron(menu, A_BLINK);
				mvwprintw(menu, 3, 3, "HARD");
				wattroff(menu, A_BLINK);
				
				mvprintw(3, 21, "height: 15 width: 30");
				
				break;
			
			case RETURN:
				wattron(menu, A_BLINK);
				mvwprintw(menu, 4, 3, "RETURN");
				wattroff(menu, A_BLINK);
				
				if(key == '\n') {
					item_number = 1;
					return 0;
				}
		}
		
		if(key == '\n') start(item_number);
		
		wrefresh(menu);
		usleep(100000);
		refresh();
		
		wresize(menu, DIFFICULTY_HEIGHT, DIFFICULTY_WIDTH);
		
	}
}

int rules_menu() {
	delwin(menu);
	menu = newwin(RULES_HEIGHT, RULES_WIDTH, 0, 0);
	keypad(menu, TRUE);
	nodelay(menu, TRUE);
	while(1) {
		
		key = wgetch(menu);
		
		if(key == 27) return 0;
		
		clear();
		wclear(menu);
		
		box(menu, 0, 0);
		mvwprintw(menu, 0, 1, "RULES");
		mvwprintw(menu, 1, 2, "The main goal of this game is to collect points");
		mvwprintw(menu, 2, 2, "and survive as long as you can. The snake won't stop");
		mvwprintw(menu, 3, 2, "moving until its game over.");
		mvwprintw(menu, 5, 2, "The game has 2 new rules: ");
		mvwprintw(menu, 6, 2, "1. When the player reaches 10 points, a \"bomb\" starts");
		mvwprintw(menu, 7, 2, "   appearing after next point. If the snake hits the bomb,");
		mvwprintw(menu, 8, 2, "   player loses 2 points and the tail gets longer.");
		mvwprintw(menu, 9, 2, "2. After the snake reaches length of 40, walls turn to red");
		mvwprintw(menu, 10, 2, "   and are no longer passable. It'll be instant game over ");
		mvwprintw(menu, 11, 2, "   if the snake hits the wall.");
		mvwprintw(menu, 13, 2, "Press ESC to return");
		
		wrefresh(menu);
		usleep(100000);
		refresh();
	}
}