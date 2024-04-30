#ifndef CURSES_H
#define	CURSES_H

#define	clear()	cpm_clr()

#ifndef	ESC
#define	ESC	27
#endif

void initscr();
void noecho();
void curs_set();
void movaddch();
void endwin();

#endif