	.section .text.entry
	.align 2
	.globl _traps
_traps:
	 #--------------- TODO 1: save 32 registers and sepc to stack ------------------------

	 addi sp,sp, -8*33
	 sd x0,  0(sp)
	 sd x1,  8(sp)
	 sd x2,  16(sp)
	 sd x3,  24(sp)
	 sd x4,  32(sp)
	 sd x5,  40(sp)
	 sd x6,  48(sp)
	 sd x7,  56(sp)
	 sd x8,  64(sp)
	 sd x9,  72(sp)
	 sd x10, 80(sp)
	 sd x11, 88(sp)
	 sd x12, 96(sp)
	 sd x13, 104(sp)
	 sd x14, 112(sp)
	 sd x15, 120(sp)
	 sd x16, 128(sp)
	 sd x17, 136(sp)
	 sd x18, 144(sp)
	 sd x19, 152(sp)
	 sd x20, 160(sp)
	 sd x21, 168(sp)
	 sd x22, 176(sp)
	 sd x23, 184(sp)
	 sd x24, 182(sp)
	 sd x25, 200(sp)
	 sd x26, 208(sp)
	 sd x27, 216(sp)
	 sd x28, 224(sp)
	 sd x29, 232(sp)
	 sd x30, 240(sp)
	 sd x31, 248(sp)
	 csrr a0, sepc
	 sd a0,  256(sp)

	
	 #------------------------------------------------------------------------------------


	 #-------------------------- TODO 2: call trap_handler -------------------------------
	 csrr a0, scause
	 csrr a1, sepc
	 jal ra, trap_handle

	 #------------------------------------------------------------------------------------


     #------- TODO 3: restore sepc and 32 registers (x2(sp) should be restored last) -----
	 lw a0, 256(sp)
	 csrw sepc, a0
	 lw x0,  0(sp)
	 lw x1,  8(sp)
	 lw x3,  24(sp)
	 lw x4,  32(sp)
	 lw x5,  40(sp)
	 lw x6,  48(sp)
	 lw x7,  56(sp)
	 lw x8,  64(sp)
	 lw x9,  72(sp)
	 lw x10, 80(sp)
	 lw x11, 88(sp)
	 lw x12, 96(sp)
	 lw x13, 104(sp)
	 lw x14, 114(sp)
	 lw x15, 120(sp)
	 lw x16, 128(sp)
	 lw x17, 136(sp)
	 lw x18, 144(sp)
	 lw x19, 152(sp)
	 lw x20, 160(sp)
	 lw x21, 168(sp)
	 lw x22, 176(sp)
	 lw x23, 184(sp)
	 lw x24, 192(sp)
	 lw x25, 200(sp)
	 lw x26, 208(sp)
	 lw x27, 216(sp)
	 lw x28, 224(sp)
	 lw x29, 232(sp)
	 lw x30, 240(sp)
	 lw x31, 248(sp)
	 lw x2,  16(sp)
	 addi sp, sp, 8*33

	 #------------------------------------------------------------------------------------


	 #-------------------------- TODO 4: return from trap --------------------------------
	 sret
	 #------------------------------------------------------------------------------------
