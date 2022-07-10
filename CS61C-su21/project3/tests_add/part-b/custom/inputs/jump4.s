addi t0, x0, 3
L0:
and t2, t2, t2
jalr a0, t0, 17
add t3, t2, t2
L1:
addi t0, x0, 26
jalr t1, t0, 25
sub t4, x0, t3
L2:
jalr t2, t4, 56
L5:
jalr t3, x0, 76
mul t5, t4, t3
L4:
sll t6, t5, t4
addi t2, x0, -94
jalr t6, t2, 126
mulhu a0, t6, t5
L3:
addi t3, x0, 49
jalr t3, t3, -9
addi t0, x0, 3
L00:
beq t0, x0 end
addi t0, t0, -1
end:
addi x1, x0, 84
jalr x2, x1, 0