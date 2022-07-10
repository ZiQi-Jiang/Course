#include "defs.h"
.extern start_kernel
.extern task_init
.extern early_pgtbl
    .section .text.init #<------- put  _start into .text.init section
   .globl _start
_start:
    # ------------------
    # - your code here -
    # ------------------
    la sp,boot_stack
	#la stvec, _traps   # set stevc = _traps
	la a0, _traps
	csrrw x0, stvec, a0
	#--------------------------------------
	# target: set sie[STIE] = 1
	addi a1,x0,0x20 # (10 0000)
	csrrs x0,sie,a1	
	#--------------------------------------

	#--------------------------------------
	# TARGET: set first time interrupt
	rdtime a0
	li a1,10000000
	add a0, a0,a1
	add a6,x0,x0
	add a7,x0,x0
	ecall
	#--------------------------------------
	
	#--------------------------------------
	# TARGET: set sstatus[SIE] = 1
	addi a1, x0, 0x2 #(10)
	csrrs x0, sstatus, a1
	#--------------------------------------
	
	jal mm_init
	#================= lab 4 ==================
    call setup_vm
	call relocate
	

	
	#================== end ===================
	
#	call setup_vm_final
	jal task_init
	j start_kernel

    #==================== implement relocate ======================
	# Your CODE
	.globl relocate
relocate:	
	li a1,VM_START
	li a2,PHY_START
	sub  a1, a1,a2 # PA2VA_OFFSET
	add  ra, ra, a1 # jump to the virtual memory
	add  sp, sp, a1 #
			
	la a0, _traps
	
	add a0, a0, a1 # add offset
	csrrw x0, stvec, a0
	la a1, early_pgtbl
	## PPN = PA >> 12
	srli a1,a1,12 # always padding 0
	li a2, 8 << 60
	or a1,a2,a1
	csrw  satp, a1
	sfence.vma
	j debug
debug:
	ret
	#======================== code end ============================

    .section .bss.stack
    .globl boot_stack
boot_stack:
#    .space XYZ # <-- change to your stack size
    .space 4096
    .globl boot_stack_top
boot_stack_top:
