#include "headers/headers.h"

int main(void) {
	srand(time(NULL));
	
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	clear();
	
	start_color();
	
	init_color(COLOR_GREY, 127, 127, 127);
	
	init_pair(1, COLOR_GREEN, COLOR_GREY);
	init_pair(2, COLOR_RED, COLOR_GREY);
	init_pair(3, COLOR_WHITE, COLOR_GREY);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	
	main_menu();
	
	clrtoeol();
	endwin();
	
}