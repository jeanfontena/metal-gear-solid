#include "inc/window.h"

void InitWindow()
{
	setlocale(LC_ALL, "en_US.utf8");
	initscr();         // Initialize the window
	noecho();          // Don't echo any keypresses
	curs_set(FALSE);   // Don't display a cursor
}
