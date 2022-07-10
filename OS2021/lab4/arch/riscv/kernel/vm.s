	.file	"vm.c"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.globl	early_pgtbl
	.bss
	.align	12
	.type	early_pgtbl, @object
	.size	early_pgtbl, 4096
early_pgtbl:
	.zero	4096
	.text
	.align	1
	.globl	setup_vm
	.type	setup_vm, @function
setup_vm:
	addi	sp,sp,-16
	sd	s0,8(sp)
	addi	s0,sp,16
	lui	a5,%hi(early_pgtbl)
	addi	a5,a5,%lo(early_pgtbl)
	li	a4,4096
	addi	a4,a4,-2033
	sd	a4,16(a5)
	lui	a5,%hi(early_pgtbl)
	addi	a5,a5,%lo(early_pgtbl)
	li	a4,4096
	add	a5,a4,a5
	li	a4,4096
	addi	a4,a4,-2033
	sd	a4,-64(a5)
	nop
	ld	s0,8(sp)
	addi	sp,sp,16
	jr	ra
	.size	setup_vm, .-setup_vm
	.ident	"GCC: (GNU) 11.1.0"
