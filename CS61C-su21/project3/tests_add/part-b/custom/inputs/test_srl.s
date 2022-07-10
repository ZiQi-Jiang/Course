addi s0, x0, 2047
addi s1, x0, -2048

srl s8, s0, t0
srl s9, t0, s8
srl s11, x0, t0

srl s8, s0, t0
srl s9, t0, s8
srl s11, x0, t0

addi a0, t0, 31
addi a1, t1, 0

srl s5, s0, a0
srl s6, s0, a1