addi s0, x0, 2047
addi s1, x0, -2048

sra s8, s0, t0
sra s9, t0, s8
sra s11, x0, t0

sra s8, s0, t0
sra s9, t0, s8
sra s11, x0, t0

addi a0, t0, 31
addi a1, t1, 0

sra s5, s0, a0
sra s6, s0, a1