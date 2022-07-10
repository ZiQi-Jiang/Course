#include "printk.h"
#include "sbi.h"

extern void test();

int start_kernel() {
//    puti(2021);
//    puts(" Hello RISC-V\n");
	//printk("2021");
	printk("Hello RISC-V\n");
	printk("idle process is running.\n");
	#ifdef SJF
		printk("\nNOTE: The Process Scheduling Algorithm is: SJF.\n");
	#else
		printk("\nNOTE: The Process Scheduling Algorithm is: PRIORITY.\n");
	#endif
    test(); // DO NOT DELETE !!!

	return 0;
}
