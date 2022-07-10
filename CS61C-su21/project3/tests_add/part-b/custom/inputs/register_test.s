add x0, x0, x0

addi a0, x0, -20
addi a1, a0, -31
addi a2, a1, 2047
add a3, a2, a1
addi a4, a1, -200
addi a5, a4, -300
addi a6, a5, -400
sub a7 a7, a6

addi t0, x0, -2003
addi t1, t0, 0
addi t2, t0, -2
addi t3, t2, -1
add t4, t3, t3
add t5, t3, t4
sub t6, t5, t0

sub s0, zero, t0
sub s1, s0, x0
mul s2, s0, s1
addi s3, s0, -40
addi s4, s0, -30
addi s5, s4, -50
addi s6, s5, 60
addi s7, x0, 70
addi s8, s7, 10
addi s9, s8, 11
addi s10, s9, 12
addi s11, s10, 13

addi ra, ra, 4
addi sp, sp, 4
addi gp, gp, 4
addi tp, tp, 4
add a0, ra, x0
sub a1, a0, tp
sub a1, a1, gp
add a0, sp, x0
