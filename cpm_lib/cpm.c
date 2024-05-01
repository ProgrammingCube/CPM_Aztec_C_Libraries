#include "cpm.h"

#asm
	public	toupper_
toupper_:
	lxi		h,2
	dad		sp
	mov		a,m
	ani		223
	ret
#endasm

#asm
	public	cpm_putc
cpm_putc:
	lxi		h,2
	dad		sp
	push	b
	mov		e,m
	mvi		c,2
	call	5
	pop		b
	ret
#endasm

#asm
	public	cpm_puts
cpm_puts:
	lxi		h,2
	dad		sp
	push	b
	mov		e,m
	dcx		h
	mov		d,m		; load string pointer
c_h_s_l:
	ldax	d		; load pointer contents to A
	cpi		0
	jz		c_h_s_e
	push	d
	mov		e,a
	mvi		c,2
	call	5
	pop		d
	inx		d
	jmp		c_h_s_l
c_h_s_e:
	mvi		e,10	; newline
	mvi		c,2
	call	5
	mvi		e,13
	mvi		c,2
	call	5
	pop		b
	ret
#endasm

#asm
	public cpm_getch
cpm_getch:
	push	b
	mvi	c,6
	mvi	e,255
	call	5
	pop	b
	ani	0FFh
	jz	cpm_getch
	ret
#endasm

void cpm_clr()
{
	cpm_puts("\033[2J\033[0H");
}

void *cpm_memset(d, b, s)
void* d;
unsigned char b;
unsigned int s;
{
	unsigned char* p = s;
	while (s--)
		*p++ = b;
	return s;
}
