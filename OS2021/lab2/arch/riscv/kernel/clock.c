// clock.c
#include"sbi.h"
#include"printk.h"
unsigned long TIMECLOCK = 1000000;

unsigned long get_cycles(){
	// write inline assemble code using rdtime to get the value time register(i.e. mtime register) 
	// and return this value.
	
	register unsigned long res asm("a0");
	__asm__  __volatile__("rdtime a0"

				: "+r"(res)
				::);
	
	return res;

}


void clock_set_next_event()
{
	// set the time of next time interrupt
	unsigned long next = get_cycles() + TIMECLOCK;
	sbi_ecall(0,0,next,0,0,0,0,0);
	printk("Timer Intruption set.\n");
	return ;
	// use sbi_ecall to finish the setting of the next clock interrupt event.

}
