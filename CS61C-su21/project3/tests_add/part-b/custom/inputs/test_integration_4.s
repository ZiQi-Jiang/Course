addi sp, sp, -12
sw s0, 0(sp)
sw ra, 4(sp)
addi s0, sp, 12
sw a1, -12(s0)
sw a2, -8(s0)
lw a3, 0(s0)
mul a3, a3, a3
addi sp, sp, 12