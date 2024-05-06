#include "conio.h"

/* clrscr()
 * getch()
 * getche()
 * putch()
 * https://www.naukri.com/code360/library/what-is-conio-h-in-c
 */

#asm
	public	kbhit_
toupper_:
	push	b
	mvi	c,6
	mvi	e,255
	call	5
	pop	b
	ret
#endasm