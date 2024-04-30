#include "curses.h"

void initscr()
{
	clear();
}

void noecho()
{
	
}

void curs_set( c )
unsigned char c;
{
	if ( c )
		puts("\033[?25h");
	else
		puts("\033[?25l");
}

void mvaddch( y, x, c )
unsigned char y, x, c;
{
	printf("\033[%d;%dH", y, x);
        putchar(c);
}

void endwin()
{
	curs_set( 1 );
}