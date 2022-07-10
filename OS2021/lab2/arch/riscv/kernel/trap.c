// trap.c
#include "printk.h"
extern void clock_set_next_event();
void trap_handle(unsigned long scause, unsigned long spec){
	// accroding to the risc-v privilege:
	// if  scause[SXLEN-1] = 1, the trap is an interrupt
    //			(1) if scause[SXLEN-2:0] = 5, it is a timer interrupt
	//			(2) else ignore the trap
	int SXLEN = 64;
	unsigned long isInterrupt = scause >> (SXLEN-1);
	unsigned long isTimer =( ((scause <<1)>>1) == 5);
	if (isInterrupt && isTimer) 
	{
		clock_set_next_event();
		printk("kernel is running!\n");
		printk("[S] Supervisor Mode Timer Interrupt\n");
		
	}
	return ;
}
