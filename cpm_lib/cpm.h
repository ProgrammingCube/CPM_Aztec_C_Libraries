#ifndef	CPM_H
#define	CPM_H

#undef	putchar(x)
#define	putchar(x)	cpm_putc(x)
#define	getch()		cpm_getch()
#define	puts(x)		cpm_puts(x)
#define	memset(x)	cpm_memset(x)

void cpm_clr();
void *cpm_memset();

#endif
