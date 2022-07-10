addi t0, x0, 1
addi t1, x0, -2
addi t2, t2, 200
sw t0, 0(t2)
sw t1, 4(t2)

lw t0, 4(t2)
lw t1, 0(t2)

beq t0, t1, inf_loop
bltu t0, t1, inf_loop
blt t1, t0, inf_loop

bne t1, t0, end

inf_loop:
	add x0 x0 x0
	beq x0 x0 inf_loop

end:
	xori s0 s0 4
	sw s0 0(t2)
	lw t0 0(t2)
	beq t0 s0 end_2

end_2:
	addi t0, x0, 456
	addi t1, x0, 789
	beq s0 x0 inf_loop
	mul t0 s0 t1
	mulhu t1 s0 t1
	beq t0 t1 inf_loop
	mulh t0 t0 t1
	jal ra f
	addi t1, x0, 1
	beq t0 t1 end_3

f:
	addi s1, x0, 987
	lb t0 0(s1)

end_3:
	add x0 x0 x0