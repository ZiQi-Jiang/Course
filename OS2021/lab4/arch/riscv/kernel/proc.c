//arch/riscv/kernel/proc.c
#include"proc.h"
#include"printk.h"
#include "defs.h"
#include"rand.h"
#include"mm.h"
extern void __dummy();
extern void __switch_to(struct task_struct*prev, struct task_struct* next);
struct task_struct* idle;           // idle process
struct task_struct* current;        // 指向当前运行线程的 `task_struct`
struct task_struct* task[NR_TASKS]; // 线程数组，所有的线程都保存在此

void printInfo()
{
	for(int i=0;i<NR_TASKS;i++)
	{
		printk("The %d-th process Info:\n",i);
		printk("pid:%d\n",task[i]->pid);
		printk("address:%ld\n",(uint64)task[i]);
	}
}

void dummy()
{
	uint64 MOD = 1000000007;
	int auto_inc_local_var = 0;
	int last_counter = -1;
	while(1){
		if (last_counter == -1 || current->counter != last_counter){
			last_counter = current->counter;
			auto_inc_local_var = (auto_inc_local_var + 1) % MOD;
			//printk("[PID = %d] is running. auto_inc_local_var = %d\n", current->pid, auto_inc_local_var);
	
		
			printk("[PID = %d] is running! thread space begin at 0x%lx\n",current->pid,(uint64)current);
			}
	}
}
void task_init() {
    // 1. 调用 kalloc() 为 idle 分配一个物理页
    // 2. 设置 state 为 TASK_RUNNING;
    // 3. 由于 idle 不参与调度 可以将其 counter / priority 设置为 0
    // 4. 设置 idle 的 pid 为 0
    // 5. 将 current 和 task[0] 指向 idle
	uint64 p = kalloc();
	idle = (struct task_struct*)p;
	idle->state = TASK_RUNNING;
	idle->pid = 0;
	idle->priority = 0;
	idle->counter = 0;
	//idle->thread.sp = p + PGSIZE;
	//idle->thread.ra =(uint64) __dummy;// the function's  name is it's address.
	task[0] = idle;
	current = idle;
    /* YOUR CODE HERE */
	
	
    // 1. 参考 idle 的设置, 为 task[1] ~ task[NR_TASKS - 1] 进行初始化
    // 2. 其中每个线程的 state 为 TASK_RUNNING, counter 为 0, priority 使用 rand() 来设置, pid 为该线程在线程数组中的下标。
    // 3. 为 task[1] ~ task[NR_TASKS - 1] 设置 `thread_struct` 中的 `ra` 和 `sp`,
    // 4. 其中 `ra` 设置为 __dummy （见 4.3.2）的地址， `sp` 设置为 该线程申请的物理页的高地址

    /* YOUR CODE HERE */
	for(int i=1; i<NR_TASKS; i++)
	{
		uint64 p = kalloc();
		task[i] = (struct task_struct*)p;
		task[i]->state = TASK_RUNNING;
		task[i]->pid = i;
		task[i]->counter = 0;
		task[i]->priority = rand();
		task[i]->thread.sp = p+PGSIZE;
		task[i]->thread.ra = (uint64)__dummy;
	}
    printk("...proc_init done!\n");
}



void do_timer(void) {
    /* 1. 如果当前线程是 idle 线程 直接进行调度 */
    /* 2. 如果当前线程不是 idle 对当前线程的运行剩余时间减 1
          若剩余时间任然大于0 则直接返回 否则进行调度 */

    /* YOUR CODE HERE */
	if(current->pid == 0)
	{
		schedule();
	}
	else
	{ // decrease the thread time by 1
	current->counter --;
	if(current->counter>0) return;
	else schedule();
	
	}
	return ;
}


#ifdef SJF

void switch_to(struct  task_struct* next)
{
//	printInfo();
//	printk("Current pid is %d, address is %ld\n",current->pid,(uint64)current);
//	printk("Next pid is %d, address is %ld\n",next->pid,(uint64)next);
	/* YOUR CODE HERE */
	if(current->pid != next->pid)
	{
		printk("\nswitch to [PID = %d COUNTER = %d]\n",next->pid,next->counter);
	struct task_struct* tmp = current;
	current = next;
	__switch_to(tmp,next);
//		current = next;
	}
	return ;
}


void schedule()
{	
	int index = -1;
	uint64 minTime= 2147483647;// In rand.c
	for(int i=1; i< NR_TASKS; i++)
	{
		if(task[i]->counter>0 && task[i]->counter<minTime)
		{
		 
			minTime = task[i]->counter;
			index = i;
		}
	}

	if(index == -1)// all zero
	{
		printk("\n");
		for(int i=1; i<NR_TASKS; i++)
		{
		uint64 counter = rand();
		task[i]->counter = counter;
		printk("SET [PID = %d COUNTER = %d]\n",i,counter);
		}
		schedule();
	}
	else
	{
//		printk("Index: %d\n",index);
		switch_to(task[index]);
	}
	
}

#else

// DPRIORITY


void schedule()
{	
	int index = -1;
	uint64 maxPriority= 0;// In rand.c
	int minTime = 0;
	for(int i=1; i< NR_TASKS; i++)
	{
		if(task[i]->counter>0 && task[i]->priority >= maxPriority)
		{
			if(task[i]->priority > maxPriority)// Case 1:Bigger Priority First
			{
			maxPriority = task[i]->priority;
			index = i;
			minTime = task[i]->counter;
			}
			else // Case2:equal priority ==> SJF
			{
			if(task[i]->counter < minTime)
		    	{
				index = i;
				minTime = task[i]->counter;
				
		        }
			}
		}
	}

	if(index == -1)// all zero
	{
		printk("\n");
		for(int i=1; i<NR_TASKS; i++)
		{
		uint64 counter = rand(),priority = rand();
		task[i]->counter = counter; task[i]->priority = priority;
		printk("SET [PID = %d PRIORITY = %d COUNTER = %d]\n",i,priority,counter);
		}
		schedule();
	}
	else
	{
//		printk("Index: %d\n",index);
		switch_to(task[index]);
	}
	
}



void switch_to(struct  task_struct* next)
{
	/* YOUR CODE HERE */
	if(current->pid != next->pid)
	{
		printk("\nswitch to [PID = %d PRIORITY = %d COUNTER = %d]\n",next->pid,next->priority,next->counter);
	struct task_struct* tmp = current;
	current = next;
	__switch_to(tmp,next);
//		current = next;
	}
	return ;
}

#endif







